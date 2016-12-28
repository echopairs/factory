//
// Created by zsy on 12/27/16.
//


#include <iostream>
#include <src/process/process.h>
#include <src/process/runner.h>

namespace tasks {

    bool Process::Register(std::shared_ptr<tasks::IRunner> runner)
    {
        if (runner == nullptr)
        {
            // TODO log
            return false;
        }
        std::lock_guard<std::mutex>lk(_runnersMutex);
        auto item = _runners.find(runner->get_name());
        if (item == _runners.end())
        {
            _runners[runner->get_name()] = runner;
        }
    }

    void Process::UnRegister(std::string runner_name)
    {
        std::lock_guard<std::mutex> lk(_runnersMutex);
        _runners.erase(runner_name);
    }

    void Process::Start()
    {
        std::lock_guard<std::mutex> lk(_runnersMutex);
        for (auto &item : _runners)
        {
            item.second->Run();
        }
    }

    void Process::Stop()
    {
        std::lock_guard<std::mutex> lk(_runnersMutex);
        for(auto &item : _runners)
        {
            item.second->Stop();
        }
    }

    void Process::StopRunner(std::string runner_name)
    {
        std::lock_guard<std::mutex> lk(_runnersMutex);
        auto item = _runners.find(runner_name);
        if (item != _runners.end())
        {
            item->second->Stop();
        }
    }

    void Process::StartRunner(std::string runner_name)
    {
        std::lock_guard<std::mutex> lk(_runnersMutex);
        auto item = _runners.find(runner_name);
        if (item != _runners.end())
        {
            item->second->Run();
        }
    }

    Process::~Process()
    {
        Stop();
    }

}

