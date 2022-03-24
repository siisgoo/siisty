#ifndef PROFILE_HPP
#define PROFILE_HPP

#include <QWidget>

namespace Ui {
class Profile;
}

class Profile : public QWidget
{
    Q_OBJECT

public:
    explicit Profile(QWidget *parent = nullptr);
    ~Profile();

private:
    Ui::Profile *ui;
};

#endif // PROFILE_HPP
