#ifndef NOTIFYITEMFACTORY_HPP_VOFLIWUB
#define NOTIFYITEMFACTORY_HPP_VOFLIWUB

#include "Widgets/NotifyItem.hpp"

class FloatNotifier;

class NotifyItemFactory {
    public:
        NotifyItemFactory();
        virtual ~NotifyItemFactory();

        virtual NotifyItem * produce(QWidget * p = nullptr) = 0;

    protected:
        friend class FloatNotifier;

        void setTitle(const QString&);
        void setNotifyType(NotifyItem::NotifyType);
        void setActivationDuration(int ms);
        void setDiactivationDuration(int ms);
        void setActivationAnimation(QPropertyAnimation *);
        void setDiactivationAnimation(QPropertyAnimation *);
        void setMinimumSize(const QSize&);

        QString _title;
        NotifyItem::NotifyType _type;
        int _aDur;
        int _daDur;
        QPropertyAnimation * _aAnimation;
        QPropertyAnimation * _daAnimation;
        QSize _minSize;
};

#endif /* end of include guard: NOTIFYITEMFACTORY_HPP_VOFLIWUB */
