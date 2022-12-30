## 设置CMake最低版本
#cmake_minimum_required(VERSION 3.10)
#
## 设置工程名称和其他相关信息
#project(
#		"epp"  # 项目名称
#		LANGUAGES CXX # 设置编程语言
#)
#
## 设置C++版本
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_EXTENSIONS OFF)
#
## 编译器配置 代码地址无关性
#set(CMAKE_CXX_FLAGS "-fPIC")
#
## 忽略警告
#add_definitions(-w)
#
## 设置子目标
#set(EPP_LIB "epp")
#set(EPP_APP "eppapplication")
#
## 设置EPP_LIB要包含的源文件（递归添加）
#file(GLOB_RECURSE EPP_LIB_SRC_FILES "src/Epp/*.cpp")
#
## 设置EPP_APP要包含的源文件（递归添加）
#file(GLOB_RECURSE EPP_APP_SRC_FILES "src/app/*.cpp")
#
## 设置链接的动态库列表
#set(LINKED_LIBS_LIST)
#
## 设置要查找的头文件列表
#set(INCLUDE_DIRS_LIST
#		src/Epp     # 默认查找src/Epp下头文件
#		)
#
#
## ----------------------------------------------------------------------------------------------------
## 以上为通用配置信息
## ----------------------------------------------------------------------------------------------------
#
## 设置构建目标
#set(TARGET "Android")
#
## 启用SDL2支持
#function(USE_SDL2_SUPPORT)
#	# 添加SDL2支持宏
#	add_definitions(-DUSE_SDL2_SUPPORT)
#
#	list(APPEND LINKED_LIBS_LIST
#			SDL2
#			)
#endfunction()
#
## 启用X11支持
#function(USE_X11_SUPPORT)
#	add_definitions(-DUSE_X11_SUPPORT)  # 添加X11支持宏
#
#	list(APPEND LINKED_LIBS_LIST
#			X11
#			Xrender
#			)
#endfunction()
#
## Linux系统
#function(SET_TARGET)
#	# 打印主机系统信息
#	message(STATUS "The Target is set to ${TARGET}")
#
#	# 目标系统为 Linux
#	if (${TARGET} STREQUAL "Linux")
#		# 添加Linux环境宏
#		add_definitions(-DCURRENT_OS_LINUX)
#
#		# 启用SDL2支持
#		USE_SDL2_SUPPORT()
#
#		# 启用X11支持
#		USE_X11_SUPPORT()
#
#		# 添加Linux下需要的头文件目录
#		list(APPEND INCLUDE_DIRS_LIST
#				/usr/include
#				/usr/include/c++/12.2.0
#				/usr/include/c++/12.2.0/backward
#				/usr/include/c++/12.2.0/x86_64-pc-linux-gnu
#				/usr/lib/gcc/x86_64-pc-linux-gnu/12.2.0/include
#				/usr/lib/gcc/x86_64-pc-linux-gnu/12.2.0/include-fixed
#				/usr/local/include
#				)
#	endif ()
#
#	# 目标系统为 MacOS
#	if (${TARGET} STREQUAL "MacOS")
#		# 添加MacOS环境宏
#		add_definitions(-DCURRENT_OS_MACOS)
#
#		# 启用SDL2支持
#		USE_SDL2_SUPPORT()
#	endif ()
#
#	# 目标系统为 Windows
#	if (${TARGET} STREQUAL "Windows")
#		# 添加Windows环境宏
#		add_definitions(-DCURRENT_OS_WINDOWS)
#
#		# 启用SDL2支持
#		USE_SDL2_SUPPORT()
#	endif ()
#
#	# 目标系统为 Android
#	if (${TARGET} STREQUAL "Android")
#		# 添加Android环境宏
#		add_definitions(-DCURRENT_OS_ANDROID)
#
#		file(GLOB_RECURSE NDK_INCLUDE
#				"/Softwares/Develop/android-sdk/ndk/23.1.7779620/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/include/*.h"
#				)
#
#		# 添加Android下需要的头文件目录
#		list(APPEND INCLUDE_DIRS_LIST
#				${NDK_INCLUDE}
#				)
#
#		# 查找android-log库
#		find_library(
#				log-lib
#				log)
#
#		# 添加Android下需要的动态库
#		list(APPEND LINKED_LIBS_LIST
#				android
#				${log-lib}
#				)
#	endif ()
#
#endfunction()
#
## ----------------------------------------------------------------------------------------------------
## 以下为通用配置信息
## ----------------------------------------------------------------------------------------------------
#
## 设置构建目标
#SET_TARGET()
#
## 设置包含头文件目录列表
#include_directories(${INCLUDE_DIRS_LIST})
#
## 生成动态链接库
#add_library(
#		${EPP_LIB}     # 要生成的动态链接库名称
#		SHARED            # 动态链接
#		${EPP_LIB_SRC_FILES}    # 源代码集合
#)
#
## 链接EPP_LIB需要的动态库
#target_link_libraries(
#		${EPP_LIB}    # 目标为EPP_LIB
#		${LINKED_LIBS_LIST}  # 要链接的动态库列表
#)
#
## 生成可执行文件，如果是Android，则生成动态库
#if (${TARGET} STREQUAL "Android")
#	add_library(
#			${EPP_APP}    # 要生成的可执行文件名称
#			SHARED            # 动态链接
#			${EPP_APP_SRC_FILES}    # 源代码集合
#	)
#
#	# 链接EPP_APP需要的动态库
#	target_link_libraries(
#			${EPP_APP}    # 目标为EPP_APP
#			${EPP_LIB}
#	)
#else ()
#	add_executable(
#			${EPP_APP}    # 要生成的可执行文件名称
#			${EPP_APP_SRC_FILES}    # 源代码集合
#	)
#
#	# 链接EPP_APP需要的动态库
#	target_link_libraries(
#			${EPP_APP}    # 目标为EPP_APP
#			${EPP_LIB}
#	)
#endif ()


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

# 编译器配置 代码地址无关性
set(CMAKE_CXX_FLAGS "-fPIC")

# 忽略警告
add_definitions(-w)

# 设置子目标
set(EPP_LIB "epp")
set(EPP_APP "eppapplication")

# 设置EPP_LIB要包含的源文件（递归添加）
file(GLOB_RECURSE EPP_LIB_SRC_FILES "src/Epp/*.cpp")

# 设置EPP_APP要包含的源文件（递归添加）
file(GLOB_RECURSE EPP_APP_SRC_FILES "src/app/*.cpp")

# ----------------------------------------------------------------------------------------------------
# 以上为通用配置信息
# ----------------------------------------------------------------------------------------------------

# 目标系统为 Android

# 添加Android环境宏
add_definitions(-DCURRENT_OS_ANDROID)

include_directories(
		includes
		# /Softwares/Develop/android-sdk/ndk/23.1.7779620/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/include
		src/Epp
)

# 生成动态链接库
add_library(
		${EPP_LIB}     # 要生成的动态链接库名称
		SHARED            # 动态链接
		${EPP_LIB_SRC_FILES}    # 源代码集合
)

# 查找NDK下动态库
# pthread，被编译为libc.so
find_library(
		ndk-lib-c
		c)

# log
find_library(
		ndk-lib-log
		log)

# 链接EPP_LIB需要的动态库
target_link_libraries(
		${EPP_LIB}    # 目标为EPP_LIB
		${ndk-lib-c}
		android
		${ndk-lib-log}
)

# 生成可执行文件，如果是Android，则生成动态库
add_library(
		${EPP_APP}    # 要生成的可执行文件名称
		SHARED            # 动态链接
		${EPP_APP_SRC_FILES}    # 源代码集合
)

# 链接EPP_APP需要的动态库
target_link_libraries(
		${EPP_APP}    # 目标为EPP_APP
		${EPP_LIB}
		# android
		# ${ndk-lib-log}
)
