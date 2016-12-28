#include <iostream>
#include <src/url/url_factory.h>
#include <src/url/url_runner.h>
#include <src/process/process.h>

using namespace std;

int main()
{
    /// 0. create process (the container of runner)
    auto process = std::make_shared<tasks::Process>();
    /// 1. create factory
    auto factory = std::make_shared<tasks::UrlFactory>();
    /// 2. create Runner
    auto UrlRunner = std::make_shared<tasks::url::UrlRunner>(factory);
    /// 3. Register Runner To process
    process->Register(UrlRunner);
    try
    {
        /// 4. start process
        process->Start();

    }
    catch(std::exception &exception1)
    {
        std::cout << exception1.what() << std::endl;
        exit(-1);
    }

    while(1)
    {}

}