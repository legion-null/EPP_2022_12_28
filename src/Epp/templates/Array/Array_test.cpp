#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::templates;


i32 templates_Vector_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	Array<String> array;

	array.addElement("劳逸结合是不错，但也别放松过头。");
	array.addElement("有时明月无人夜，独向昭潭制恶龙。");
	array.addElement("阴阳有序，命运无常，死亡难以预测，却也有它的规矩。");
	array.addElement("律法即是约束，也是工具。");
	array.addElement("赌徒永远会把希望寄托在下一颗骰子上，但最后赚钱的，当然是从来不碰骰子的庄家。");

	array.paintAllElements();
	array[4] = "世界？？？？遗忘我？？";
	array.paintAllElements();
	array.deleteElement(0);
	array.paintAllElements();
	array.addElement("劳逸结合是不错，但也别放松过头。");
	array.paintAllElements();

	return 0;
}
