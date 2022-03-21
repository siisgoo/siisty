#include "Widgets/FloatNotifier.hpp"

#include <QStandardItemModel>
#include <algorithm>
#include <qnamespace.h>

FloatNotifier::FloatNotifier(QWidget * mainWindow,
                             QMargins margins,
                             QSize itemSize,
                             int maxActive,
                             int completeTimeout,
                             StackType stacking,
                             QObject * parent)
    : QObject(parent),
        _win(mainWindow),
        _margins(margins),
        _spacing(2),
        _activationDur(1500),
        _diactivationDur(1000),
        _completeTimeout(completeTimeout),
        _stack(stacking),
        _maxActiveItems(maxActive),
        _hideOnClick(true),
        _imtSize(itemSize)
{
    _winSize = _win->size();
    connect(this, SIGNAL(windowResized(QResizeEvent*)), this, SLOT(reorganize()));
    connect(this, SIGNAL(maxWidthChanged(int)), this, SLOT(resizeItems(int)));
}

FloatNotifier::~FloatNotifier()
{
    for (auto i : _items) {
        delete i;
    }
}

int
FloatNotifier::freeUID()
{
    static int i = INT_MIN+1;
    if (i == INT_MAX-1) { // may crash if you have INT_MAX+(-INT_MIN) notifies at one time
                        // but im think its imposible
        i = INT_MIN+1;
    }
    return i++;
}

void
FloatNotifier::setItemPropery(int uid, const QByteArray& name, const QVariant& value)
{
    QMutexLocker lock(&_mtx);
    if (_items.contains(uid)) {
        _items[uid]->setProperty(name, value);
    } else {
        qDebug() << "FloatNotifier::" << __func__ << " Trying assign unexist notify item. Item uid";
    }
}

void
FloatNotifier::createNotifyItem(NotifyItemFactory * factory, int& uid)
{
    {
        QMutexLocker lock(&_mtx);
        uid = freeUID();

        factory->setActivationDuration(_activationDur);
        factory->setDiactivationDuration(_diactivationDur);
        factory->setMinimumSize(_imtSize);
        NotifyItem * item = factory->produce(_win);

        _items[uid] = item;

        item->setUID(uid);
        item->activate(NextPosition(activeItemsCount()-1));

        connect(item, SIGNAL(clicked()), this, SLOT(hideItem()));
        connect(item, SIGNAL(completed()), this, SLOT(on_itemCompleted()));
        connect(item, SIGNAL(diactivated()), this, SLOT(reorganize()));
    }
    reorganize();
}

void
FloatNotifier::reorganize()
{
    QMutexLocker lock(&_mtx);
    findMaxItemWidth();
    _winSize = _win->size();
    QList<NotifyItem *> active_bars = activeItems();
    struct {
        bool operator()(QWidget* a, QWidget* b) const { return a->pos().y() > b->pos().y(); };
    } posCheck;
    std::sort(active_bars.begin(), active_bars.end(), posCheck);

    int i = 0;
    for (auto bar : active_bars) {
        bar->move(NextPosition(i++));
        bar->adjustSize();
    }
}

void
FloatNotifier::resizeItems(int w)
{
    for (auto i : _items) {
        i->setMinimumWidth(w);
        i->adjustSize();
    }
    /* reorganize(); */
}

int
FloatNotifier::findMaxItemWidth()
{
    int w = 0;
    QList<NotifyItem *> active = activeItems([](NotifyItem*i){ return i->isNotActivated() || i->isOnActivation() || i->isOnDiactivation(); });

    for (auto itm : active) {
        if (!itm) {
            continue;
          }
        if (itm->sizeHint().width() > w) {
            w = std::max(_imtSize.width(), itm->sizeHint().width());
        }
    }

    if (w != _prevMaxWidth) {
        _prevMaxWidth = w;
        Q_EMIT maxWidthChanged(w);
    }

    return w;
}

// TODO handle diff size items
QPoint
FloatNotifier::NextPosition(int i)
{
    const int winw = _winSize.width(),
              winh = _winSize.height(),
              itmw = _prevMaxWidth,
              itmh = _imtSize.height();
    QPoint pos = {winw - itmw - _margins.right(), // first item pos
                  winh - itmh - _margins.bottom() };

    if (i > 0) {
        pos.ry() -= i*(itmh + _spacing);
    }

    return pos;
}

int
FloatNotifier::activeItemsCount(std::function<bool(NotifyItem*)> filter)
{
    return activeItems(filter).length();
}

QList<NotifyItem*>
FloatNotifier::activeItems(std::function<bool(NotifyItem*)> filter) const
{
    QList<NotifyItem*> active;
    for (auto item : _items) {
        /* if (!item->isHidden() && !item->isOnDiactivation() && !item->isOnActivation()) { */
        if (filter(item) || (!item->isHidden() && !item->isOnDiactivation())) {
            active.append(item);
        }
    }
    return active;
}

int FloatNotifier::itemsCount() { return _items.count(); }

void
FloatNotifier::on_itemCompleted()
{
    NotifyItem * item = dynamic_cast<NotifyItem *>(sender());
    QTimer::singleShot((item->completeTimeout() ? item->completeTimeout() : _completeTimeout), [this, item]() {
        connect(item, SIGNAL(diactivated()), this, SLOT(removeItem()), Qt::SingleShotConnection);
        item->diactivate();
    });
}

void
FloatNotifier::removeItem()
{
    NotifyItem * item = dynamic_cast<NotifyItem *>(sender());
    {
        QMutexLocker lock(&_mtx);
        _items.remove(item->UID());
        delete item;
    }
    reorganize();
}

void
FloatNotifier::hideItem()
{
    if (_hideOnClick) {
        NotifyItem * item = dynamic_cast<NotifyItem *>(sender());
        connect(item, SIGNAL(diactivated()), item, SLOT(hide()), Qt::SingleShotConnection);
        item->diactivate();
    }
}
