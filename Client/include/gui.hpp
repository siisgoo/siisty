#ifndef QT_SSL_EXAMPLE_CLIENT_GUI_H__
#define QT_SSL_EXAMPLE_CLIENT_GUI_H__

#include <QWidget>
#include <QPointer>
#include <QPushButton>
#include <QTextEdit>
#include <QThread>

#include "General/logger.hpp"
#include "manager.hpp"

class userInterface : public QWidget
{
    Q_OBJECT
    public:
        userInterface(QWidget *parent = NULL);
        virtual ~userInterface();

    public Q_SLOTS:
        void startService();
        void stopService();
        void logMessage(QString _message);

    Q_SIGNALS:
        void start_service();
        void stop_service();
        void send_to_log(QString _message);

    protected:
        QPointer<QTextEdit> textDisplay;
        QPointer<QPushButton> buttonStart;
        QPointer<QPushButton> buttonStop;

        // thread that runs the file logger
        QThread loggingThread;
        logger log;

        QThread serviceThread;
        manager theManager;

        void createLayout();
};

#endif // QT_SSL_EXAMPLE_CLIENT_GUI_H__
