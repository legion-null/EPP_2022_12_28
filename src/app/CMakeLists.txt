# 设置工程名称和其他相关信息
project(
	"eppapplication"  # 项目名称
	LANGUAGES CXX # 设置编程语言
)

# ----------------------------------------------------------------------------------------------------
# 编译器相关信息（通用）：
# ----------------------------------------------------------------------------------------------------

# 设置C++版本
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

#set(CMAKE_CXX_VISIBILITY_PRESET default)
#set(CMAKE_VISIBILITY_INLINES_HIDDEN 0)

# 编译器配置 代码地址无关性
set(CMAKE_CXX_FLAGS "-fPIC")

# 忽略警告
add_definitions(-w)

# 添加目标系统环境宏
add_definitions(-DEPP_TARGET_OS_ANDROID)

# 设置此项目要包含的源文件（递归添加）
file(GLOB_RECURSE EPP_SRC_FILES "./*.cpp")

# 设置头文件包含目录列表，默认包含EPP目录
set(EPP_INCLUDE_DIRS_LIST
	../Epp
	.
	)

# 生成动态链接库
add_library(
	${PROJECT_NAME} # 要生成的动态链接库名称
	SHARED    # 动态链接
	${EPP_SRC_FILES}    # 源代码集合
)

# 设置头文件包含目录
target_include_directories(
	${PROJECT_NAME} # 项目名称
	PRIVATE
	${EPP_INCLUDE_DIRS_LIST} # 包含头文件目录列表
)

# 链接需要用到的动态库
target_link_libraries(
	${PROJECT_NAME} # 项目名称
	epp
)

