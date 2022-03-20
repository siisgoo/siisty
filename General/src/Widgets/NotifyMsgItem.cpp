#include "Widgets/NotifyMsgItem.hpp"

NotifyMsgItem::NotifyMsgItem(const QString& title,
                             const QString& msg,
                             NotifyLevel notifyLevel,
                             int completeTmeout,
                             int activationDuration,
                             int diactivationDuration,
                             QSize sizeHints,
                             QWidget* p)
    : NotifyItem(title, notifyLevel, completeTmeout, activationDuration, diactivationDuration, sizeHints, p)
{
    _msg = new QLabel(msg, this);
    _msg->setWordWrap(true);
}

NotifyMsgItem::~NotifyMsgItem()
{
    delete _msg;
}
