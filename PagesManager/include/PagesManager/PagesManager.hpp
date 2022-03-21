#ifndef PAGESMANAGER_HPP_AC3HJAY0
#define PAGESMANAGER_HPP_AC3HJAY0

#include <QPair>
#include <QDebug>
#include <QMap>
#include <QWidget>
#include <QString>

class PagesManager {
    private:
        PagesManager();
        PagesManager(const PagesManager&) = delete;
        PagesManager& operator = (const PagesManager&) = delete;

        struct Page {
            QWidget * widget;
            int navId;
            QVector<QString> edges;
        };

        QList<Page> _pages;
        QString _root;

    public:

        static PagesManager&  instance();

        static int pages();
        static void addRoot(const QString& accessName, QWidget*, int nav,
                            const QVector<QString>& edges = {});
        static void addPage(const QString& accessName, QWidget*, int nav,
                            const QVector<QString>& edges = {});
        static QWidget* getPage(const QString& name);
        static int getPageNav(const QString& name);
        static QVector<QString> getPagePath(const QString& name);
        /* static QWidget * getPage(const int n); */

        ~PagesManager();
};

#endif /* end of include guard: PAGESMANAGER_HPP_AC3HJAY0 */
