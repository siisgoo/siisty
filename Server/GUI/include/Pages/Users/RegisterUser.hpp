#ifndef REGISTERUSER_H
#define REGISTERUSER_H

#include <QWidget>
#include "Database/Database.hpp"

namespace Ui {
  class RegisterUser;
}

class RegisterUser : public QWidget {
    Q_OBJECT

    public:
        explicit RegisterUser(QWidget *parent = nullptr);
        ~RegisterUser();

    Q_SIGNALS:
        void registrateUser(QJsonObject& o);

    private:
        Ui::RegisterUser *ui;
};

#endif // REGISTERUSER_H
