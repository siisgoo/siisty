#include "Widgets/Progresses.hpp"

#include <QStandardItemModel>
#include <qnamespace.h>

ProgressItem::ProgressItem(int max, QString title, QWidget* p)
    : QFrame(p), _progress(new QProgressBar(this))
{
    auto effect = new QGraphicsOpacityEffect(this);
    this->setGraphicsEffect(effect);
    _animation = new QPropertyAnimation(effect, "opacity");
    _animation->setDuration(200);
    _animation->setStartValue(0);
    _animation->setEndValue(1);
    _animation->setEasingCurve(QEasingCurve::InCubic);

    this->setWindowFlag(Qt::WindowType::Widget);
    this->setFixedSize(200, 40);

    _layout = new QVBoxLayout(this);
    this->setLayout(_layout);

    _title = new QLabel(title);
    _title->setFont(QFont("JetBrains Mono NL Thin", 7));

    connect(_progress, SIGNAL(valueChanged(int)), this, SIGNAL(progressChanged(int)));
    _progress->setRange(0, max);
    _progress->setFormat("");
    _progress->setMinimumSize(200-24, 12);
    _progress->setMaximumHeight(12);
    _progress->setAlignment(Qt::AlignHCenter);

    this->layout()->setAlignment(Qt::AlignHCenter);
    this->layout()->addWidget(_title);
    this->layout()->addWidget(_progress);
}

ProgressItem::~ProgressItem()
{
    delete _progress;
}

void
ProgressItem::forseComplete()
{
    auto effect = new QGraphicsOpacityEffect();
    this->setGraphicsEffect(effect);
    QPropertyAnimation * a = new QPropertyAnimation(effect, "opacity");
    a->setDuration(500);
    a->setStartValue(1);
    a->setEndValue(0);
    a->setEasingCurve(QEasingCurve::InBack);
    a->start(QPropertyAnimation::DeleteWhenStopped);
    connect(a, SIGNAL(finished()), this, SIGNAL(completed()));
}

void
ProgressItem::activate()
{
    this->show();
    _animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void
ProgressItem::mousePressEvent(QMouseEvent * e)
{
    if (e->button() == Qt::MouseButton::LeftButton) {
        Q_EMIT clicked();
    }
}

void ProgressItem::setProgress(int v) {
    _progress->setValue(v);
    if (v == _progress->maximum()) {
        auto effect = new QGraphicsOpacityEffect();
        this->setGraphicsEffect(effect);
        QPropertyAnimation * a = new QPropertyAnimation(effect, "opacity");
        a->setDuration(500);
        a->setStartValue(1);
        a->setEndValue(0);
        a->setEasingCurve(QEasingCurve::InBack);
        a->start(QPropertyAnimation::DeleteWhenStopped);
        connect(a, SIGNAL(finished()), this, SIGNAL(completed()));
    }
}

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

pSetProgress::pSetProgress(QWidget *w, QMargins mrgns, QWidget * p)
    : QObject(p),
        _win(w),
        _margins(mrgns),
        _spacing(2)
{
    connect(this, SIGNAL(setProgress(int,int,QString,int)), this, SLOT(on_setProgress(int, int, QString, int)));
    connect(this, SIGNAL(windowResized(QResizeEvent*)), this, SLOT(pBarReorganize()));
}

pSetProgress::~pSetProgress()
{
    for (auto p : _bars) {
        delete p;
    }
}

void
pSetProgress::pBarReorganize()
{
    struct {
        bool operator()(QWidget* a, QWidget* b) const { return a->pos().y() > b->pos().y(); };
    } posCheck;
    QList<ProgressItem*> pbars = _bars.values();
    std::sort(pbars.begin(), pbars.end(), posCheck);

    int i = 0;
    for (auto bar : pbars) {
        bar->move(pBarNextPosition(i++));
    }
}

void
pSetProgress::pBarCompleted()
{
    ProgressItem* bar = dynamic_cast<ProgressItem*>(sender());
    _bars.remove(bar->objectName().toInt());
    delete bar;
    pBarReorganize();
}

QPoint
pSetProgress::pBarNextPosition(int i)
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

/* void */
/* pSetProgress::pBarFadeOut(QProgressBar * bar) */
/* { */
/* } */

void
pSetProgress::on_setProgress(int cur, int max, QString title, int uid)
{
    QMutexLocker lock(&_mtx);

    if (!_bars.contains(uid)) {
        _bars[uid] = new ProgressItem(max,title, _win);
        _bars[uid]->setObjectName(QString::number(uid)); // for delete from qmap

        connect(_bars[uid], SIGNAL(clicked()), this, SLOT(pBarCompleted()));
        connect(_bars[uid], SIGNAL(completed()), this, SLOT(pBarCompleted()));

        _bars[uid]->move(pBarNextPosition(_bars.count()-1));
        _bars[uid]->activate();
    }

    _bars[uid]->setProgress(cur);
}

