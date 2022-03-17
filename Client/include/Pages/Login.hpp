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

    private:
        Ui::Login *ui;
};

#endif // LOGIN_HPP
