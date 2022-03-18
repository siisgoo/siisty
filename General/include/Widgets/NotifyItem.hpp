#ifndef NOTIFYITEM_HPP_WKRUDOKF
#define NOTIFYITEM_HPP_WKRUDOKF

#include <QObject>
#include <QWidget>
#include <QPropertyAnimation>
#include <QFrame>
#include <QProgressBar>
#include <QLabel>
#include <QPushButton>
#include <QLayout>

class NotifyItem : public QFrame {
    Q_OBJECT

    // add properties

    public:
        enum NotifyType {
            NotifySuccess,
            NotififyNormal,
            NotifyWarning,
            NotifyError,
        };
        Q_ENUM(NotifyType)

        NotifyItem(const QString& title, NotifyType notifyType,
                   int activationDuration,
                   int diactivationDuration,
                   QPropertyAnimation* activationAnimation,
                   QPropertyAnimation* diactivationAnimation,
                   QSize = {160, 42},
                   QWidget* p = nullptr);
        virtual ~NotifyItem();

        NotifyType notifyType() const;

        bool isOnDiactivation() const;

    Q_SIGNALS:
        void clicked();
        void resized(QResizeEvent*);
        void onDiactivation(); // disapear animation started
        void diactivated(); // disapear animation completed
        void completed(); // progress 100%

    public Q_SLOTS:
        void setSchemeByType(NotifyType);

        void setNotifyType(NotifyType);
        void setTitle(const QString&);
        void activate(const QPoint& pos);
        void forseComplete();
        void diactivate();

    protected Q_SLOTS:
        virtual void mousePressEvent(QMouseEvent*) override;
        /* virtual void resizeEvent(QResizeEvent*) override; */

    protected:
        NotifyType _notifyType;
        bool _diactivating;
        QLabel       * _title;
        /* QPushButton  * _closeBtn; */
        QVBoxLayout  * _layout;

        QSize _minSize;

        int  _activationDur;
        int  _diactivationDur;
        QPropertyAnimation * _activationAnimation;
        QPropertyAnimation * _diactivationAnimation;
};

#endif /* end of include guard: NOTIFYITEM_HPP_WKRUDOKF */
