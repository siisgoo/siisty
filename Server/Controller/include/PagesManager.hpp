#ifndef PAGESMANAGER_HPP_AC3HJAY0
#define PAGESMANAGER_HPP_AC3HJAY0

#include <QPair>
#include <QWidget>
#include <QString>

class PagesManager {
    private:
        PagesManager();
        PagesManager(const PagesManager&) = delete;
        PagesManager& operator = (const PagesManager&) = delete;

        QList<QPair<QWidget*, int>> _pages;
            // page - nav_pag

    public:

        static PagesManager&  instance();

        static int pages();
        static void addPage(const QString&, QWidget *, int);
        static QWidget * getPage(const QString& name);
        static int getPageNav(const QString& name);
        /* static QWidget * getPage(const int n); */

        ~PagesManager();
};

#endif /* end of include guard: PAGESMANAGER_HPP_AC3HJAY0 */
