#set(CMAKE_CXX_VISIBILITY_PRESET default)
#set(CMAKE_VISIBILITY_INLINES_HIDDEN 0)

# 发布模式
# set(CMAKE_BUILD_TYPE "Release")
# add_definitions(-DEPP_TARGET_DEBUG)

set(CMAKE_BUILD_TYPE "Debug")
add_definitions(-DEPP_TARGET_DEBUG)

# 设置编译目标
set(EPP_TARGET "Linux")

# epp构建
add_subdirectory(Epp)

# eppapplication构建
add_subdirectory(app)

# tools构建
# add_subdirectory(tools)
