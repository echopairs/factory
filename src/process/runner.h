//
// Created by zsy on 12/27/16.
//

#ifndef TASKS_RUNNER_H
#define TASKS_RUNNER_H

#include <atomic>
#include <string>
#include <thread>

namespace tasks {

    class IRunner
    {
    public:
        void Stop();
        IRunner(std::string name);
        virtual  void Run() = 0;
        virtual ~IRunner();

        const std::string &get_name() const;


        std::shared_ptr<std::thread> _runThread;
        std::atomic<bool> _is_running;
        std::string _name;
        std::atomic<bool>_stop;
    };
}

#endif //TASKS_RUNNER_H
