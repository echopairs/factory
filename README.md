## factory
Task-based project based on the abstract factory pattern

## Introduction
factory/
  |- bin/               项目构建生成的二进制输出目录（排除在版本控制库之外） 
  |- build/             项目构建的工作目录 （排除在版本控制库之外） 
  |- include/           发布需要的头文件目录 
  |- release/           使用发布脚本发布的二进制文件保存目录 （排除在版本控制库之外） 
  |- src/               项目源代码目录 
  |   |- equipment/ 		设备管理模块(TODO)        
  |   |- Ifactory/          抽象工厂和抽象任务接口模块 
  |   |- process/           进程运行模块 
  |   |- url              	url处理模块 
  |- tools/             构建/发布/测试等相关脚本 
  |- main.cpp			入口函数 
  
 ##Requirement
  
  ###Tools
  1. cmake >= 3.5
  2. g++5.3.1
  3. ftp
  
  ##Build
  1. 构建
  ./tools/build_without_lib_update.sh
  ### Test
  
##Tips
1. 每个进程中含有一个process实例
2. process实例中可注册多个runner
3. 每个runner中含有一个工厂,生产一类任务，已实现url runner



