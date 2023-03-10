#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace base {

const Class *Error::ClassInfo = Class::Register<Error, Exception>("Epp::base::Error", nullptr);

Error* Error::UnknownError() {
	return new Error("Unknown Error");
}

Error::Error() {

}

Error::Error(const String &info) {
	static const i8 重置所有属性 = 0;
	static const i8 高亮_加粗 = 1;
	static const i8 暗淡 = 2;
	static const i8 下划线 = 3;
	static const i8 闪烁 = 4;
	static const i8 反转 = 5;
	static const i8 隐藏 = 6;

	static const i8 黑色背景 = 40;
	static const i8 红色背景 = 41;
	static const i8 绿色背景 = 42;
	static const i8 黄色背景 = 43;
	static const i8 蓝色背景 = 44;
	static const i8 紫色背景 = 45;
	static const i8 深绿色背景 = 46;
	static const i8 白色背景 = 47;

	static const i8 黑色字体 = 30;
	static const i8 红色字体 = 31;
	static const i8 绿色字体 = 32;
	static const i8 黄色字体 = 33;
	static const i8 蓝色字体 = 33;
	static const i8 紫色字体 = 35;
	static const i8 深绿色字体 = 36;
	static const i8 白色字体 = 37;

	(void) 重置所有属性;
	(void) 高亮_加粗;
	(void) 暗淡;
	(void) 下划线;
	(void) 闪烁;
	(void) 反转;
	(void) 隐藏;

	(void) 黑色背景;
	(void) 红色背景;
	(void) 绿色背景;
	(void) 黄色背景;
	(void) 蓝色背景;
	(void) 紫色背景;
	(void) 深绿色背景;
	(void) 白色背景;

	(void) 黑色字体;
	(void) 红色字体;
	(void) 绿色字体;
	(void) 黄色字体;
	(void) 蓝色字体;
	(void) 紫色字体;
	(void) 深绿色字体;
	(void) 白色字体;

	OS::Printf("\033[%d;%dm%s\033[0m", 隐藏, 红色字体, info.getValue());
	OS::Printf("\n");
}

}
}
