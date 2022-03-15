#include "PagesManager.hpp"
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
PagesManager::addPage(const QString& name, QWidget * wp, int nav)
{
    auto& pages = PagesManager::instance()._pages;
    wp->setObjectName(name);
    //add check for existance
    pages.append({wp, nav});
}

QWidget *
PagesManager::getPage(const QString& name)
{
    auto& pages = PagesManager::instance()._pages;
    for (auto it : pages) {
        if (it.first->objectName() == name) {
            return it.first;
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
        if (it.first->objectName() == name) {
            return it.second;
        }
    }

    return -1;
}
