#ifndef DATABASEPAGE_H
#define DATABASEPAGE_H

#include <QWidget>

namespace Ui {
class DatabasePage;
}

class DatabasePage : public QWidget
{
    Q_OBJECT

public:
    explicit DatabasePage(QWidget *parent = nullptr);
    ~DatabasePage();

private:
    Ui::DatabasePage *ui;
};

#endif // DATABASEPAGE_H
