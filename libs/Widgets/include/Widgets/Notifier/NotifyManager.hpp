#ifndef PROGRESSES_HPP_ANX5GJAI
#define PROGRESSES_HPP_ANX5GJAI

#include <QMainWindow>
#include <QMargins>
#include <QMutexLocker>
#include <QWaitCondition>
#include <QResizeEvent>
#include <QTimer>
#include <QVariant>

#include "Widgets/Notifier/NotifyItem.hpp"
#include "Widgets/Notifier/NotifyItemFactory.hpp"

// TODO reanme as NotifyManager
// Dont move this in another thread
class NotifyManager : public QObject {
    Q_OBJECT

    /* Q_PROPERTY(int maxItemWidth MEMBER _prevMaxWidth NOTIFY maxWidthChanged) */

    public:
        // TODO
        enum StackDirection {
            StackAbove,
            StackUnder,
        };

        // TODO
        enum DockArea {
            DockLeft,
        };

        explicit NotifyManager(QWidget* mainWindow,
                               QMargins margins,
                               QSize _itemSize,
                               int maxVisible = 5, //  TODO
                               StackDirection stacking = StackAbove,
                               QObject* p = nullptr);
        virtual ~NotifyManager();

        static int freeUID();

        void setDiactivationDur(int ms);
        void setActivationDur(int ms);

        int diactivationDur() const;
        int activationDur() const;

        void setDiactivationAnimation(QPropertyAnimation* a);
        void setActivationAnimation(QPropertyAnimation* a);

        const QPropertyAnimation* diactivationAnimation() const;
        const QPropertyAnimation* activationAnimation() const;

    Q_SIGNALS:
        void windowResized(QResizeEvent*);
        void maxWidthChanged(int);

    public Q_SLOTS:
        int activeItemsCount(std::function<bool(NotifyItem*)> filter = [](NotifyItem*){return false;});
        QList<NotifyItem*> activeItems(std::function<bool(NotifyItem*)> filter = [](NotifyItem*){return false;}) const;
        int itemsCount();

        void setItemPropery(int uid, const QByteArray& name, const QVariant& value);
        void createNotifyItem(NotifyItemFactory*, int& uid);
            // creates notify item in main thread and return as param
            // use Qt::BlockingQueuedConnection for connection

    private Q_SLOTS:
        int findMaxItemWidth();
        QPoint NextPosition(int n);
        void reorganize();
        void resizeItems(int width);
        void hideItem();
        void removeItem();

    private:
        /*const*/ QWidget* _win;  // link
        QMap<int, NotifyItem*> _items;
        QMutex _mtx;
        QWaitCondition _created;
        QMargins _margins;
        int _spacing;

        QSize _winSize;

        int _prevMaxWidth = 0;

        bool _hideOnClick;
        QSize _itemHints;
            // width - maximum avalible width
            // height - fixed item height
        StackDirection _stackDir;
        int _maxActiveItems;
        int _activationDur;
        int _diactivationDur;
};

#endif /* end of include guard: PROGRESSES_HPP_ANX5GJAI */
