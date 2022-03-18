#include "Widgets/FloatNotifier.hpp"

#include <QStandardItemModel>
#include <qnamespace.h>

FloatNotifier::FloatNotifier(QWidget *w, QMargins mrgns, QWidget * p)
    : QObject(p),
        _win(w),
        _margins(mrgns),
        _spacing(2)
{
    connect(this, SIGNAL(setProgress(int,int,int,QString)), this, SLOT(on_setProgress(int, int, int, QString)));
    connect(this, SIGNAL(windowResized(QResizeEvent*)), this, SLOT(reorganize()));
}

FloatNotifier::~FloatNotifier()
{
    for (auto i : _items) {
        delete i;
    }
}

void
FloatNotifier::createNotifyItem(NotifyItemFactory * factory)
{
    NotifyItem * itm = factory->produce(_win);
    Q_EMIT notifyItemCreated(itm);
}

void
FloatNotifier::reorganize()
{
    QList<NotifyItem *> active_bars;

    for (auto i : _items) {
        if (!i->isHidden() && !i->isOnDiactivation()) {
            active_bars.append(i);
        }
    }
    struct {
        bool operator()(QWidget* a, QWidget* b) const { return a->pos().y() > b->pos().y(); };
    } posCheck;
    std::sort(active_bars.begin(), active_bars.end(), posCheck);

    int i = 0;
    for (auto bar : active_bars) {
        bar->move(NextPosition(i++));
    }
}

void
FloatNotifier::on_itemCompleted()
{
    NotifyItem * item = dynamic_cast<NotifyItem *>(sender());
    _items.remove(item->objectName().toInt());
    delete item;
}

void
FloatNotifier::on_itemDiactivation()
{
    reorganize();
}

void
FloatNotifier::hideItem()
{
    NotifyItem * item = dynamic_cast<NotifyItem *>(sender());
    item->diactivate();
    connect(item, SIGNAL(diactivated()), item, SLOT(hide()));
    connect(item, SIGNAL(diactivated()), this, SLOT(reorganize()));
}

QPoint
FloatNotifier::NextPosition(int i)
{
    const int winw = _win->size().width(),
              winh = _win->size().height(),
              itmw = 200, itmh = 40; // TODO
    QPoint pos = {winw - itmw - _margins.right(),
                  winh - itmh - _margins.bottom() };

    if (i > 0) {
        pos.ry() -= i*(itmh + _spacing);
    }

    return pos;
}

int
FloatNotifier::activeItemsCount()
{
    int i = 0;
    for (auto item : _items) {
        if (!item->isHidden() && !item->isOnDiactivation()) {
            i++;
        }
    }
    return i;
}

int
FloatNotifier::freeUID()
{
    static int i = 0;
    return i++;
}
