# cmake最低版本号要求
cmake_minimum_required(VERSION 3.0)
# 指定的项目名
project(SWAP)
# 添加头文件目录
include_directories(include)
add_executable(main_cmake main.cpp src/mytime2.cpp) 
# add_executable(main_cmake main.cpp) 

# file(GLOB native_srcs "src/*.cpp")
# add_library( 
#     # set the name of the library
#     native-lib
#     # set the library as a shared library.
#     SHARED

#     # provides a relative path to your source file(s)
#     # Associated headers in the same location as their source
#     # file are automatically included
#     ${native_srcs}

# )


