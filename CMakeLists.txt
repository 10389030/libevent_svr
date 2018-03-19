# cmake 最低版本要求
cmake_minimum_required (VERSION 2.8)

# 项目名
project (libevent_svr)
include_directories(${CMAKE_ROOT})

# print command before execute
# set(CMAKE_VERBOSE_MAKEFILE on)
SET(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -O3 -std=c++11 -Wall")
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -std=c++11 -Wall -g -ggdb")
# SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -std=c++11 -Wall")

# 依赖外部模块定义在 modules 目录
SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

FIND_PACKAGE(libevent REQUIRED) # 查找 libevent
FIND_PACKAGE(libglog REQUIRED) # 查找 libglog
FIND_PACKAGE(libgtest REQUIRED) # 查找 libgtest

# 添加子目录
add_subdirectory(protocal)
add_subdirectory(toolkit)
add_subdirectory(test)

# 查找当前目录下所有源文件，并将名称保存到变量DIR_SRCS
aux_source_directory(. DIR_SRCS)

# 指定生成可执行文件
add_executable(event_svr ${DIR_SRCS})
# 指定依赖
target_link_libraries(event_svr toolkit)
target_link_libraries(event_svr protocal)
target_link_libraries(event_svr event)
target_link_libraries(event_svr glog)




