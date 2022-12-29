# 系统环境

# 启用SDL2
function(USE_LIB_SDL2)
    add_definitions(-DUSE_LIB_SDL2)
endfunction()

# 设置目标系统环境
function(SET_TARGET_OS OS)
    # 打印主机系统信息
    message(STATUS "The host system is set to ${OS}")

    if (${OS} STREQUAL "Linux")
        add_definitions(-DCURRENT_OS_LINUX)
        USE_LIB_SDL2()
    elseif (${OS} STREQUAL "MacOS")
        add_definitions(-DCURRENT_OS_MACOS)
        USE_LIB_SDL2()
    elseif (${OS} STREQUAL "Windows")
        add_definitions(-DCURRENT_OS_WINDOWS)
        USE_LIB_SDL2()
    elseif (${OS} STREQUAL "Android")
        add_definitions(-DCURRENT_OS_ANDROID)
    endif ()
endfunction()

# 获取主机系统环境
function(GET_HOST_OS OS)
    if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
        set(${OS} "Linux" PARENT_SCOPE)
    elseif (CMAKE_SYSTEM_NAME STREQUAL "DarWin")
        set(${OS} "MacOS" PARENT_SCOPE)
    elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
        set(${OS} "Windows" PARENT_SCOPE)
    else ()
        set(${OS} "Unknown" PARENT_SCOPE)
    endif ()
endfunction()

set(TARGET_OS "Android")
SET_TARGET_OS(${TARGET_OS})

# 编译工具链