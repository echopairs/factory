//
// Created by zsy on 12/27/16.
//

#ifndef TASKS_IFACTORY_H
#define TASKS_IFACTORY_H

#include <memory>

namespace tasks {

    class ITask;
    class IFactory
    {
    public:
       virtual std::shared_ptr<ITask>AcquireTask(int type) = 0;
    };
}

#endif //TASKS_IFACTORY_H
