#ifndef NOTIFYPROGRESSFACTORY_HPP_5JG6ZKSA
#define NOTIFYPROGRESSFACTORY_HPP_5JG6ZKSA

#include "Widgets/NotifyItemFactory.hpp"

class FloatNotifier;

class NotifyProgressItemFactory : public NotifyItemFactory {
    public:
        NotifyProgressItemFactory();
        virtual ~NotifyProgressItemFactory();

        virtual NotifyItem * produce(QWidget * p = nullptr) override;

    protected:
        friend class FloatNotifier;
        void setMaximum(int maxProgress);
        void setExitOnCompleted(bool exit);

        int _maxProgress;
        bool _exitOnComplete;
};


#endif /* end of include guard: NOTIFYPROGRESSFACTORY_HPP_5JG6ZKSA */
