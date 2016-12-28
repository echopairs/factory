//
// Created by zsy on 12/27/16.
//

#include <iostream>
#include <src/process/runner.h>

namespace tasks {

    void IRunner::Stop()
    {
        _stop = true;
    }

    IRunner::IRunner(std::string name):_stop(false),_is_running(false),_name(name)
    {
    }

    IRunner::~IRunner()
    {
        _stop = true;
        _runThread->join();
    }

    const std::string &IRunner::get_name() const
    {
        return _name;
    }


} // namespace task


