# 查找当前目录下所有源文件，并将名称保存到变量DIR_SRCS
aux_source_directory(. DIR_SRCS)

# 生成静态库
add_library (protocal ${DIR_SRCS})



