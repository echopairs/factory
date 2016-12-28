//
// Created by zsy on 12/27/16.
//

#ifndef TASKS_PROCESS_H
#define TASKS_PROCESS_H


#include <memory>
#include <map>
#include <mutex>

namespace tasks {

class IRunner;
    class Process
    {
    public:
        bool Register(std::shared_ptr<IRunner>runner);
        void UnRegister(std::string runner_name);
        void Start();
        void Stop();
        ~Process();
    private:
        void StopRunner(std::string runner_name);
        void StartRunner(std::string runner_name);

        std::mutex _runnersMutex;
        std::map<std::string, std::shared_ptr<IRunner>> _runners;
    };
} // namesapce task
#endif //TASKS_PROCESS_H
