#include "PagesManager/PagesManager.hpp"
#include <functional>

PagesManager::PagesManager() { }
PagesManager::~PagesManager() { }

PagesManager&
PagesManager::instance()
{
    static PagesManager _pmInstance;
    return _pmInstance;
}

int
PagesManager::pages() {
    auto& pages = PagesManager::instance()._pages;
    return pages.size();
}

void
PagesManager::addRoot(const QString& name, QWidget* wp, int nav,
                      const QVector<QString>& edges)
{
    auto& root = PagesManager::instance()._root;
    root = name;
    PagesManager::instance().addPage(name, wp, nav, edges);
}

void
PagesManager::addPage(const QString& name, QWidget* wp, int nav,
                      const QVector<QString>& edges)
{
    if (!wp) {
        throw QString("empty widgt pathed");
    }
    if (nav < 0) {
        throw QString("Anavalible nav id passeed");
    }
    auto& pages = PagesManager::instance()._pages;
    wp->setObjectName(name);
    //add check for existance
    pages.append({wp, nav, edges});
}

QWidget *
PagesManager::getPage(const QString& name)
{
    auto& pages = PagesManager::instance()._pages;
    for (auto it : pages) {
        if (it.widget->objectName() == name) {
            return it.widget;
        }
    }

    return nullptr;
}

//merge funcs
//TODO

int
PagesManager::getPageNav(const QString& name)
{
    auto& pages = PagesManager::instance()._pages;
    for (auto it : pages) {
        if (it.widget->objectName() == name) {
            return it.navId;
        }
    }

    return -1;
}

QVector<QString>
PagesManager::getPagePath(const QString& page)
{
    auto& pages = PagesManager::instance()._pages;
    auto& root = PagesManager::instance()._root;
    QVector<QString> path { page };
    QString search = page;
    bool done = false;
    int tries = 0;

    while (!done && tries < pages.size() + 1) {
        for (auto i : pages) {
            if (search == root) {
                done = true;
                break;
            }
            for (auto node : i.edges) {
                if (node == search) {
                    search = i.widget->objectName();
                    path.push_front(search);
                    // exit outer?
                    break;
                }
            }
        }
        tries++;
    }

    return path;
}
