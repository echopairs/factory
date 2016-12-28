//
// Created by zsy on 12/27/16.
//

#include <src/url/url_task.h>
#include <iostream>

namespace  tasks {

    /// Get URL TASK
    GetUrlTask::GetUrlTask(std::string carmeID, std::shared_ptr<Connect> con):_carme_id(carmeID),_conn_handle(con)
    {

    }

    void GetUrlTask::Process()
    {
        // TODO
        std::cout << "process  get url task  " << std::endl;
    }

    ///

    tasks::PushUrlTask::PushUrlTask(std::shared_ptr<tasks::Connect> con):_con_handle(con)
    {
    }

    void PushUrlTask::Process()
    {
        // TODO
        std::cout << "process push url to db task " << std::endl;
    }

    tasks::RecycleUrlTask::RecycleUrlTask() {

    }

    void RecycleUrlTask::Process()
    {
        // TODO
        std::cout << "Process Recycle Url task " << std::endl;
    }

}



