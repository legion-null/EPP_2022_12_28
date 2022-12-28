# 系统环境

# 设置主机系统环境
function(SET_HOST_OS OS)
	# 打印主机系统信息
	message(STATUS "The host system is set to ${OS}")

	if(${OS} STREQUAL "Linux")
	    add_definitions(-DCURRENT_OS_LINUX)
	elseif(${OS} STREQUAL "MacOS")
	    add_definitions(-DCURRENT_OS_MACOS)
	elseif(${OS} STREQUAL "Windows")
	    add_definitions(-DCURRENT_OS_WINDOWS)
	endif()
endfunction()

# 获取主机系统环境
function(GET_HOST_OS OS)
	if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
		set(${OS} "Linux" PARENT_SCOPE)
	elseif(CMAKE_SYSTEM_NAME STREQUAL "DarWin")
		set(${OS} "MacOS" PARENT_SCOPE)
	elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
		set(${OS} "Windows" PARENT_SCOPE)
	else()
		set(${OS} "Unknown" PARENT_SCOPE)
	endif()
endfunction()

SET_HOST_OS("Linux")

# 编译工具链