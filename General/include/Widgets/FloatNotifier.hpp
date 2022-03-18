#ifndef PROGRESSES_HPP_ANX5GJAI
#define PROGRESSES_HPP_ANX5GJAI

#include <QWaitCondition>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QMainWindow>
#include <QTimer>
#include <QMutexLocker>
#include <QMargins>
#include <QProgressBar>
#include <QResizeEvent>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QEasingCurve>

#include "Widgets/NotifyItem.hpp"
#include "Widgets/NotifyItemFactory.hpp"

// worst name in uniwerse
class FloatNotifier : public QObject {
    Q_OBJECT

    public:
        explicit FloatNotifier(QWidget * mw, QMargins margins, QWidget * p = nullptr);
        virtual ~FloatNotifier();

        static int freeUID();

        void setDiactivationDur(int ms);
        void setActivationDur(int ms);

        int diactivationDur() const;
        int activationDur() const;

        void setDiactivationAnimation(QPropertyAnimation* a);
        void setActivationAnimation(QPropertyAnimation* a);

        const QPropertyAnimation * diactivationAnimation() const;
        const QPropertyAnimation * activationAnimation() const;

    Q_SIGNALS:
        void windowResized(QResizeEvent*);
        void notifyItemCreated(NotifyItem *);

    public Q_SLOTS:
        void createNotifyItem(NotifyItemFactory *);

    private Q_SLOTS:
        int activeItemsCount();
        QPoint NextPosition(int n);
        void reorganize();
        void hideItem();
        void on_itemCompleted(); // timeout completed and end animation finished
        void on_itemDiactivation(); // on end animation started

    private:
        /*const*/ QWidget * _win; // link
        QMap<int, NotifyItem *> _items;
        QMutex _mtx;
        QWaitCondition _created;
        QMargins _margins;
        int _spacing;

        int _diactivationTimeout; // TODO
        int _activationDur;
        int _diactivationDur;
        QPropertyAnimation * _activationAnimation;
        QPropertyAnimation * _diactivationAnimation;
};


#endif /* end of include guard: PROGRESSES_HPP_ANX5GJAI */
