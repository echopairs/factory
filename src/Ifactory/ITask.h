//
// Created by zsy on 12/27/16.
//

#ifndef TASKS_ITASK_H
#define TASKS_ITASK_H

namespace tasks {

    class ITask
    {
    public:
        virtual void Process() = 0;
    };

}

#endif //TASKS_ITASK_H
