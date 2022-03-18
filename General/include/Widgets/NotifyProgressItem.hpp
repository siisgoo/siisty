#ifndef NOTIFYPROGRESSITEM_HPP_WF9NQV3H
#define NOTIFYPROGRESSITEM_HPP_WF9NQV3H

#include "Widgets/NotifyItem.hpp"

class NotifyProgressItem : public NotifyItem {
    Q_OBJECT

    public:
        NotifyProgressItem(bool exitOnComplete, int maxProgress, const QString& title, NotifyType notifyType,
                   int activationDuration,
                   int diactivationDuration,
                   QPropertyAnimation* activationAnimation,
                   QPropertyAnimation* diactivationAnimation,
                   QSize = {160, 42},
                   QWidget* p = nullptr);
        ~NotifyProgressItem();

    Q_SIGNALS:
        void progressChanged(int);

    public Q_SLOTS:
        void setProgress(int count);
        void endProgress(NotifyType success);

    private:
        QProgressBar * _pbar;
        bool _exitOnComplete;

};

#endif /* end of include guard: NOTIFYPROGRESSITEM_HPP_WF9NQV3H */
