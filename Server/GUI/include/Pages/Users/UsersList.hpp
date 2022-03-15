#ifndef USERSLIST_H
#define USERSLIST_H

#include <QWidget>

namespace Ui {
  class UsersList;
}

class UsersList : public QWidget
{
  Q_OBJECT

public:
  explicit UsersList(QWidget *parent = nullptr);
  ~UsersList();

private:
  Ui::UsersList *ui;
};

#endif // USERSLIST_H
