//
// Created by zsy on 12/27/16.
//

#include <src/Ifactory/ITask.h>

#ifndef TASKS_URL_TASK_H
#define TASKS_URL_TASK_H

#include <string>
#include <memory>

namespace tasks
{
    class Connect
    {
    public:
        // TODO
    };

    class UrlTask : public ITask
    {
    public:
        /// here some url task common function and attribute
        virtual void Process(){};
    private:
    };

    class GetUrlTask : public UrlTask
    {
    public:
        GetUrlTask(std::string carmeID, std::shared_ptr<Connect> con = nullptr);
        void Process() override;
    private:
        std::string _carme_id;
        std::shared_ptr<Connect> _conn_handle;
    };

    class PushUrlTask : public UrlTask
    {
    public:
        PushUrlTask(std::shared_ptr<Connect> con = nullptr);
        void Process() override;
    private:
        std::shared_ptr<Connect> _con_handle;
    };

    class RecycleUrlTask : public UrlTask
    {
    public:
        RecycleUrlTask();
        void Process() override;
    private:
    };
 }

#endif //TASKS_URL_TASK_H
