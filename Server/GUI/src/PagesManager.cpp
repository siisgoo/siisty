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
PagesManager::addPage(QWidget * wp)
{
    auto& pages = PagesManager::instance()._pages;
    //add check for existance
    pages.append(wp);
}

QWidget *
PagesManager::getPage(const QString& name)
{
    auto& pages = PagesManager::instance()._pages;
    auto it = std::find_if(pages.begin(), pages.end(),
        [name] (QWidget* w) {
            return w->objectName() == name;
    });

    if (it != pages.end()) {
        return *it;
    }

    return nullptr;
}
