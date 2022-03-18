#include "Widgets/NotifyItem.hpp"

#include <QMouseEvent>
#include <QResizeEvent>

NotifyItem::NotifyItem(const QString& title, NotifyType notifyType,
           int activationDuration,
           int diactivationDuration,
           QPropertyAnimation* activationAnimation,
           QPropertyAnimation* diactivationAnimation,
           QSize minSize,
           QWidget* p)
    : QFrame(p),
    _notifyType(notifyType),
    _activationDur(activationDuration),
    _diactivationDur(diactivationDuration),
    _activationAnimation(activationAnimation),
    _diactivationAnimation(diactivationAnimation),
    _minSize(minSize),
    _diactivating(false)
{
    this->setWindowFlag(Qt::WindowType::Widget);
    this->setMinimumSize(minSize);

    _layout = new QVBoxLayout(this);
    this->setLayout(_layout);

    _title = new QLabel(title);
    _title->setFont(QFont("JetBrains Mono", 7));

    this->layout()->setAlignment(Qt::AlignHCenter);
    this->layout()->addWidget(_title);

    this->setSchemeByType(notifyType);
}

NotifyItem::~NotifyItem()
{
    delete _title;
    /* delete _closeBtn; */
    delete _layout;
}

void
NotifyItem::setSchemeByType(NotifyItem::NotifyType t) {
    QString scheme;
    switch (t) {
        case NotifyItem::NotifySuccess: scheme = "NotifySuccess";
            break;
        case NotifyItem::NotififyNormal: scheme = "NotifyNormal";
            break;
        case NotifyItem::NotifyWarning: scheme = "NotifyWarning";
            break;
        case NotifyItem::NotifyError: scheme = "NotifyError";
            break;
    }
    this->setObjectName(scheme);
}

NotifyItem::NotifyType NotifyItem::notifyType() const { return _notifyType; }
bool NotifyItem::isOnDiactivation() const             { return _diactivating; }

void NotifyItem::setTitle(const QString& title) { _title->setText(title); }
void NotifyItem::setNotifyType(NotifyType type) { _notifyType = type; }

void
NotifyItem::forseComplete()
{
    diactivate();
    connect(this, SIGNAL(diactivated()), this, SIGNAL(completed()));
}

void
NotifyItem::diactivate()
{
    _diactivating = true;
    Q_EMIT onDiactivation();

    _diactivationAnimation->start(QPropertyAnimation::DeleteWhenStopped);
    connect(_diactivationAnimation, SIGNAL(finished()), this, SIGNAL(diactivated()));
}

void
NotifyItem::activate(const QPoint& pos)
{
    this->show();
    _activationAnimation->start(QPropertyAnimation::DeleteWhenStopped);
}

void
NotifyItem::mousePressEvent(QMouseEvent * e)
{
    if (e->button() == Qt::MouseButton::LeftButton) {
        Q_EMIT clicked();
    }
}

/* void */
/* NotifyItem::resizeEvent(QResizeEvent*) */
/* { */

/* } */
