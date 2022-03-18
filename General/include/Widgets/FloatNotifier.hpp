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

class NotifyItem : public QFrame {
    Q_OBJECT

    public:
        NotifyItem(const QString& title = "Notify", QWidget * p = nullptr);
        virtual ~NotifyItem();

        bool isOnDiactivation();

    Q_SIGNALS:
        void clicked();
        void onDiactivation(); // disapear animation started
        void diactivated(); // disapear animation completed
        void completed(); // progress 100%

    protected:
        QLabel       * _title;
        QPushButton  * _closeBtn;
        QProgressBar * _progress;
        QVBoxLayout  * _layout;
        bool _diactivating;
};

class ProgressItem : public QFrame {
    Q_OBJECT

    public:
        ProgressItem(int max, QString title = "Worker", QWidget * p = nullptr);
        ~ProgressItem();

        bool isOnDiactivation();

    Q_SIGNALS:
        void clicked();
        void onDiactivation(); // disapear animation started
        void diactivated(); // disapear animation completed
        void completed(); // progress 100%
        void progressChanged(int);

    public Q_SLOTS:
        void setTitle(const QString&);
        void activate(const QPoint& pos);
        void setProgress(int);
        void forseComplete();
        void diactivate();

    private Q_SLOTS:
        virtual void mousePressEvent(QMouseEvent*) override;

    private:
        QLabel       * _title;
        QPushButton  * _closeBtn;
        QProgressBar * _progress;
        QVBoxLayout  * _layout;
        bool _diactivating;

};

// worst name in uniwerse
class FloatNotifier : public QObject {
    Q_OBJECT

    public:
        explicit FloatNotifier(QWidget * mw, QMargins margins, QWidget * p = nullptr);
        virtual ~FloatNotifier();

        static int freeUID();

    Q_SIGNALS:
        void windowResized(QResizeEvent*);
        void setProgress(int, int, int, QString);

    private Q_SLOTS:
        int activeBars();
        QPoint NextPosition(int n);
        void reorganize();
        void hideBar();
        void on_barCompleted();
        void on_barDiactivation();

        void on_setProgress(int uid, int v, int max, QString title);

    private:
        /*const*/ QWidget * _win;
        QMap<int, ProgressItem*> _bars;
        QMutex _mtx;
        QWaitCondition _created;
        QMargins _margins;
        int _spacing;
};


#endif /* end of include guard: PROGRESSES_HPP_ANX5GJAI */
