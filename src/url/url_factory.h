//
// Created by zsy on 12/27/16.
//

#ifndef TASKS_URL_FACTORY_H
#define TASKS_URL_FACTORY_H

#include <src/Ifactory/IFactory.h>
#include <utils/time.h>


namespace  tasks {

    class UrlFactory : public IFactory
    {
    public:
        virtual std::shared_ptr<ITask>AcquireTask(int type = 0) override;
    private:
        utils::Timer _recycle_timer;
        utils::Timer _get_timer;
        utils::Timer _push_timer;
    };

}


#endif //TASKS_URL_FACTORY_H
