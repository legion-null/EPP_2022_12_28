# EPP构建相关宏
function(add_epp_build_macro name)
	add_definitions(-DEPP_TARGET_${name})
endfunction()