#ifndef SYSTEM_LOAD_PAGE_HPP
#define SYSTEM_LOAD_PAGE_HPP

#include <QWidget>

namespace Ui {
class SystemLoadPage;
}

class SystemLoadPage : public QWidget
{
    Q_OBJECT

public:
    explicit SystemLoadPage(QWidget *parent = nullptr);
    ~SystemLoadPage();

private:
    Ui::SystemLoadPage *ui;
};

#endif // SYSTEM_LOAD_PAGE_HPP
