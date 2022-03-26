#ifndef PROFILE_HPP
#define PROFILE_HPP

#include <QWidget>

#include <QJsonObject>

namespace Ui {
class Profile;
}

class Profile : public QWidget
{
    Q_OBJECT

    public:
        explicit Profile(bool HideWapon = false, QWidget *parent = nullptr);
        ~Profile();

    Q_SIGNALS:
        void loadData(QJsonObject);

    public Q_SLOTS:
        void dataLoaded(QJsonObject);

    private:
        Ui::Profile *ui;
};

#endif // PROFILE_HPP
