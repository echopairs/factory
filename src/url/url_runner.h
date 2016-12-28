//
// Created by zsy on 12/27/16.
//

#ifndef TASKS_URL_RUNNER_H
#define TASKS_URL_RUNNER_H

#include <src/process/runner.h>
#include <src/Ifactory/IFactory.h>
#include <vector>
#include <mutex>

namespace  tasks {
namespace url {

    class UrlRunner : public IRunner
    {
    public:
        UrlRunner(std::shared_ptr<IFactory>fac);
        void Run() override ;
        virtual ~UrlRunner();
    private:
        std::vector<std::shared_ptr<std::thread> > _work_threads;
        void RunCb();
        std::shared_ptr<IFactory> _factory;
        std::mutex _tasksMutex;
        void WorkThreadCb();
    };
}
}
#endif //TASKS_URL_RUNNER_H
