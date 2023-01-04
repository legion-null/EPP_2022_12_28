# 添加模块支持，通用
function(add_module_support name)
	# 添加相关宏
	add_definitions(-DEPP_TARGET_MODULE_${name}_SUPPORT)
endfunction()

# 添加SDL2模块支持
function(add_module_sdl2_support path)
	find_library(
		lib-SDL2
		sdl2
	)

	list(APPEND EPP_LINK_LIBS_LIST
		 ${lib-SDL2}
		 )

	add_module_support("SDL2")
endfunction()

# 添加X11模块支持
function(add_module_x11_support path)
	find_library(
		lib-X11
		X11
	)

	find_library(
		lib-Xrender
		Xrender
	)

	list(APPEND EPP_LINK_LIBS_LIST
		 ${lib-X11}
		 ${lib-XRender}
		 )

	add_module_support("X11")
endfunction()

# 添加LinuxFB模块支持
function(add_module_linuxfb_support path)
	find_library(
		lib-LinuxFB
		X11
	)

	list(APPEND EPP_LINK_LIBS_LIST
		 ${lib-LinuxFB}
		 )

	add_module_support("X11")
endfunction()