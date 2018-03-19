# cmake 最低版本要求

# 查找当前目录下所有源文件，并将名称保存到变量DIR_SRCS
aux_source_directory(. DIR_SRCS)

# 指定生成可执行文
add_executable(test_all ${DIR_SRCS})
target_link_libraries(test_all toolkit)
target_link_libraries(test_all protocal)
target_link_libraries(test_all event)
target_link_libraries(test_all glog)
target_link_libraries(test_all gtest)
target_link_libraries(test_all pthread)




