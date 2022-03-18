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

class ProgressItem : public QFrame {
    Q_OBJECT

    public:
        ProgressItem(int max, QString title = "Worker", QWidget * p = nullptr);
        ~ProgressItem();

    Q_SIGNALS:
        void clicked();
        void diactivated();
        void completed();
        void progressChanged(int);

    public Q_SLOTS:
        void setTitle(const QString&);
        void activate();
        void setProgress(int);
        void forseComplete();
        void diactivate();

    private Q_SLOTS:
        virtual void mousePressEvent(QMouseEvent*) override;

    private:
        QPropertyAnimation * _animation;
        QLabel       * _title;
        QPushButton  * _closeBtn;
        QProgressBar * _progress;
        QVBoxLayout  * _layout;

};

// worst name in uniwerse
class pSetProgress : public QObject {
    Q_OBJECT

    public:
        explicit pSetProgress(QWidget * mw, QMargins margins, QWidget * p = nullptr);
        virtual ~pSetProgress();

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
