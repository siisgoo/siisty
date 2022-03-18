#include "Widgets/NotifyItemFactory.hpp"

NotifyItemFactory::NotifyItemFactory()
{
}

NotifyItemFactory::~NotifyItemFactory()
{
}
void NotifyItemFactory::setTitle(const QString& t) { _title = t; }
void NotifyItemFactory::setNotifyType(NotifyItem::NotifyType t) { _type = t; }
void NotifyItemFactory::setActivationDuration(int ms) { _aDur = ms; }
void NotifyItemFactory::setDiactivationDuration(int ms) { _daDur = ms; }
void NotifyItemFactory::setActivationAnimation(QPropertyAnimation * actAnim) { _aAnimation = actAnim; }
void NotifyItemFactory::setDiactivationAnimation(QPropertyAnimation *diactAnim) { _daAnimation = diactAnim; }
void NotifyItemFactory::setMinimumSize(const QSize& s) { _minSize = s; }
