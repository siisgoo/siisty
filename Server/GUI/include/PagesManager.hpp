#ifndef PAGESMANAGER_HPP_AC3HJAY0
#define PAGESMANAGER_HPP_AC3HJAY0

#include <QWidget>
#include <QString>

class PagesManager {
    private:
        PagesManager();
        PagesManager(const PagesManager&) = delete;
        PagesManager& operator = (const PagesManager&) = delete;

        QList<QWidget*> _pages;

    public:

        static PagesManager&  instance();

        static void addPage(QWidget *);
        static QWidget * getPage(const QString& name);
        /* static QWidget * getPage(const int n); */

        ~PagesManager();
};

#endif /* end of include guard: PAGESMANAGER_HPP_AC3HJAY0 */
