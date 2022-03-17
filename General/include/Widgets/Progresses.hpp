#ifndef PROGRESSES_HPP_ANX5GJAI
#define PROGRESSES_HPP_ANX5GJAI

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
        ProgressItem(int max, QWidget * p = nullptr);
        ~ProgressItem();

    Q_SIGNALS:
        void clicked();
        void completed();
        void progressChanged(int);

    public Q_SLOTS:
        void activate();
        void setProgress(int);
        void forseComplete();

    private Q_SLOTS:
        virtual void mousePressEvent(QMouseEvent*) override;

    private:
        QLabel * _title;
        QPropertyAnimation * _animation;
        QProgressBar * _progress;
        QVBoxLayout * _layout;

};

// worst name in uniwerse
class pSetProgress : public QObject {
    Q_OBJECT

    public:
        explicit pSetProgress(QWidget * mw, QMargins margins, QWidget * p = nullptr);
        virtual ~pSetProgress();

        static int freeSlot();

    Q_SIGNALS:
        void windowResized(QResizeEvent*);
        void setProgress(int, int, int);
            // handle multithread

    private Q_SLOTS:
        QPoint pBarNextPosition(int n);
        void pBarReorganize();
        void pBarCompleted();

        void on_setProgress(int cur, int max, int uid);

    private:
        /*const*/ QWidget * _win;
        QMap<int, ProgressItem*> _bars;
        QMutex _barsMtx;
        QMargins _margins;
        int _spacing;
        QMutex _mtx;
};


#endif /* end of include guard: PROGRESSES_HPP_ANX5GJAI */
