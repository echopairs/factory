//
// Created by zsy on 12/27/16.
//

#include "url_factory.h"
#include "url_task.h"

namespace tasks {

    std::shared_ptr<ITask> tasks::UrlFactory::AcquireTask(int type) {
        /// here produce 3 kinds of url task
        /// each 3 s produce RecycleUrlTask
        /// each 1 s produce get url task
        /// each 2 s produce push url task
        std::shared_ptr<ITask> task = nullptr;
        if (_recycle_timer.ElapsedSeconds() > 1)
        {
            task = std::make_shared<RecycleUrlTask>();
            _recycle_timer.Reset();
            return task;
        }

        if (_get_timer.ElapsedSeconds() > 2)
        {
            task = std::make_shared<GetUrlTask>("cid1");
            _get_timer.Reset();
            return task;
        }

        if (_push_timer.ElapsedSeconds() > 3)
        {
            task = std::make_shared<PushUrlTask>();
            _push_timer.Reset();
            return task;
        }
        return task;
    }
} // namespace task







