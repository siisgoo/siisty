#ifndef NOTIFYMSGITEM_HPP_5QXIAV3D
#define NOTIFYMSGITEM_HPP_5QXIAV3D

#include "Widgets/NotifyItem.hpp"

class NotifyMsgItem : public NotifyItem {
    Q_OBJECT

    public:
        NotifyMsgItem(const QString& title,
                      const QString& msg,
                      NotifyLevel notifyLevel,
                      int completeTmeout,
                      int activationDuration,
                      int diactivationDuration,
                      QSize = {160, 42}, QWidget* p = nullptr);
        virtual ~NotifyMsgItem();

    protected:
        QLabel * _msg;
};


#endif /* end of include guard: NOTIFYMSGITEM_HPP_5QXIAV3D */
