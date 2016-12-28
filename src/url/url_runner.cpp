//
// Created by zsy on 12/27/16.
//
#include <src/url/url_runner.h>
#include <iostream>
#include <src/url/url_task.h>

namespace  tasks {
namespace url {

   UrlRunner::UrlRunner(std::shared_ptr<IFactory> fac):IRunner("URL"),_factory(fac)
   {
   }

    void UrlRunner::Run()
    {
        if (_is_running)
        {
            return;
        }
        _runThread = std::make_shared<std::thread>(&UrlRunner::RunCb, this);
    }

    void UrlRunner::RunCb()
    {
        for (int i = 0; i < 8; i++)
        {
            _work_threads.emplace_back(std::make_shared<std::thread>(&UrlRunner::WorkThreadCb, this));
        }
    }

    void UrlRunner::WorkThreadCb()
    {
        while(!_stop)
        {
            std::shared_ptr<ITask> task = nullptr;
            {
                std::lock_guard<std::mutex> lk(_tasksMutex);
                task = _factory->AcquireTask(0);
            }
            if (task != nullptr)
            {
                task->Process();
            }
        }
    }

    UrlRunner::~UrlRunner()
    {
        std::lock_guard<std::mutex> lk(_tasksMutex);
        for(auto &thr : _work_threads)
        {
            thr->join();
        }
    }


}
}


