# cmake 最低版本要求
cmake_minimum_required (VERSION 2.8)

# 项目名
project (libevent_svr)

# print command before execute
# set(CMAKE_VERBOSE_MAKEFILE on)
SET(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -O3 -std=c++11 -Wall")

## 依赖外部模块
# 使用pkg-config
find_package(PkgConfig)
pkg_check_modules(gtest gtest>=1.9.0)
pkg_check_modules(libevent libevent>=2.1.8)
pkg_check_modules(libglog libglog>=0.3.5)

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_PREFIX}")
LIST(APPEND CMAKE_MODULE_PATH "/usr/local/lib/cmake/Poco") # where poco install
find_package(Poco REQUIRED Foundation Util Net)

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
target_link_libraries(event_svr pthread)
target_link_libraries(event_svr Poco::Foundation)




