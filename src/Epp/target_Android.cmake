# ----------------------------------------------------------------------------------------------------
# 设置编译环境相关信息：
# ----------------------------------------------------------------------------------------------------

## 设置Android SDK目录
#set(ANDROID_SDK_PATH "/Softwares/Develop/android-sdk")
#
## 设置Android NDK总目录
#set(ANDROID_NDK_GENERAL_PATH "${ANDROID_SDK_PATH}/ndk")
#
## 设置Android NDK具体目录
#set(ANDROID_NDK_PATH "${ANDROID_NDK_GENERAL_PATH}/23.1.7779620")
#
## 设置Android NDK TOOLCHAINS目录
#set(ANDROID_NDK_TOOLCHAINS_PATH "${ANDROID_NDK_GENERAL_PATH}/toolchains")
#
## 设置Android NDK ROOT目录
#set(ANDROID_NDK_ROOT_PATH "${ANDROID_NDK_TOOLCHAINS_PATH}/llvm/prebuilt/linux-x86_64/")

# ----------------------------------------------------------------------------------------------------
# 设置EPP环境变量：
# ----------------------------------------------------------------------------------------------------

# 添加目标系统环境宏
add_definitions(-DEPP_TARGET_OS_ANDROID)

# 添加目标系统位数环境宏
add_definitions(-DEPP_TARGET_OS_64BIT)

# ----------------------------------------------------------------------------------------------------
# 添加需要的头文件包含目录：
# ----------------------------------------------------------------------------------------------------

list(APPEND EPP_INCLUDE_DIRS_LIST
	 ../../includes
	 )

#list(APPEND EPP_INCLUDE_DIRS_LIST
#	 ${ANDROID_NDK_ROOT_PATH}/lib64/clang/12.0.8/include
#	 ${ANDROID_NDK_ROOT_PATH}/sysroot/usr/include
#	 )

# ----------------------------------------------------------------------------------------------------
# 添加需要的链接库查询目录：
# ----------------------------------------------------------------------------------------------------

#list(APPEND EPP_LINK_DIRS_LIST
#	 ${ANDROID_NDK_ROOT_PATH}/sysroot/usr/lib/aarch64-linux-android
#	 ${ANDROID_NDK_ROOT_PATH}/sysroot/usr/lib/arm-linux-androideabi
#	 ${ANDROID_NDK_ROOT_PATH}/sysroot/usr/lib/i686-linux-android
#	 ${ANDROID_NDK_ROOT_PATH}/sysroot/usr/lib/x86_64-linux-android
#	 )

# ----------------------------------------------------------------------------------------------------
# 查找并添加需要的库（对于关系到代码模块化编译的部分，添加相应宏）：
# ----------------------------------------------------------------------------------------------------

find_library(lib-c c)     # libc.so -> ndk-lib-c
find_library(lib-android android)  # libandroid.so -> ndk-lib-android
find_library(lib-android-log log)  # liblog.so -> android-log

# 链接库列表添加项目项目
list(APPEND EPP_LINK_LIBS_LIST
	 ${lib-c}
	 ${lib-android}
	 ${lib-android-log}
	 )