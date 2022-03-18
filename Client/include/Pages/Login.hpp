#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <QWidget>
#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

    public:
        explicit Login(QWidget *parent = nullptr);
        ~Login();

    Q_SIGNALS:
        void tryLogin(QString, QString);

    private Q_SLOTS:
        void on_submit_clicked();
        void on_auth_changed(QString);

    private:
        Ui::Login *ui;
};

#endif // LOGIN_HPP
