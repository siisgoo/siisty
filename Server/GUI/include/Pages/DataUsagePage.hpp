#ifndef DATA_USAGE_PAGE_HPP
#define DATA_USAGE_PAGE_HPP

#include <QWidget>

namespace Ui {
class DataUsagePage;
}

class DataUsagePage : public QWidget
{
    Q_OBJECT

public:
    explicit DataUsagePage(QWidget *parent = nullptr);
    ~DataUsagePage();

private:
    Ui::DataUsagePage *ui;
};

#endif // DataUsagePage_HPP
