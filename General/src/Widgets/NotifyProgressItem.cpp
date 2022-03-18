#include "Widgets/NotifyProgressItem.hpp"

NotifyProgressItem::NotifyProgressItem(
    bool exitOnComplete,
    int maxProgress, const QString& title, NotifyType notifyType,
    int activationDuration, int diactivationDuration,
    QPropertyAnimation* activationAnimation,
    QPropertyAnimation* diactivationAnimation, QSize minSize, QWidget* p)
    : NotifyItem(title, notifyType, activationDuration, diactivationDuration,
                 activationAnimation, diactivationAnimation, minSize, p),
        _exitOnComplete(exitOnComplete),
        _pbar(new QProgressBar(this))
{
    _pbar->setRange(0, maxProgress);
    this->layout()->addWidget(_pbar);

    connect(_pbar, SIGNAL(valueChanged(int)), this, SLOT(valueChanged(int)));
}

NotifyProgressItem::~NotifyProgressItem()
{
    delete _pbar;
}

void
NotifyProgressItem::setProgress(int count)
{
    _pbar->setValue(count);
    if (count >= _pbar->maximum() && _exitOnComplete) {
        setSchemeByType(NotifySuccess);
        diactivate();
        connect(this, SIGNAL(diactivated()), this, SIGNAL(completed()));
    }
}

void
NotifyProgressItem::endProgress(NotifyType type)
{
    setSchemeByType(type);
    diactivate();
    connect(this, SIGNAL(diactivated()), this, SIGNAL(completed()));
}
