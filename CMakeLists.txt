# 设置CMake最低版本
cmake_minimum_required(VERSION 3.10)

# 设置工程名称和其他相关信息
project(
        "epp"  # 项目名称
        LANGUAGES CXX # 设置编程语言
)

# 设置C++版本
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

#
set(CMAKE_CXX_FLAGS "-fPIC")

# 包含环境相关设置
include(environment.cmake)

# 设置要包含的源文件（递归添加）
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# 将源文件和头文件一起添加到工程中
if (${TARGET_OS} STREQUAL "Android")
    # 设置要包含的头文件目录
    include_directories(
            include

            src/Epp
    )

    # 生成动态链接库
    add_library(
            ${PROJECT_NAME} # 要生成的可执行文件名称
            SHARED          # 动态链接
            ${SRC_FILES}    # 源代码集合
    )

    # 链接需要的动态库
    target_link_libraries(
            ${PROJECT_NAME} # 要生成的目标
            -lpthread
            -landroid
    )
else ()
    # 设置要包含的头文件目录
    include_directories(
            /usr/include
            /usr/include/c++/12.2.0
            /usr/include/c++/12.2.0/backward
            /usr/include/c++/12.2.0/x86_64-pc-linux-gnu
            /usr/lib/gcc/x86_64-pc-linux-gnu/12.2.0/include
            /usr/lib/gcc/x86_64-pc-linux-gnu/12.2.0/include-fixed
            /usr/local/include

            src/Epp
    )

    # 生成可执行文件
    add_executable(
            ${PROJECT_NAME} # 要生成的可执行文件名称
            ${SRC_FILES}    # 源代码集合
    )

    # 链接需要的动态库
    target_link_libraries(
            ${PROJECT_NAME} # 要生成的目标
            -lpthread
            -lSDL2
            -lX11
            -lXrender
    )
endif ()




