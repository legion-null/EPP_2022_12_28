#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::templates;

i32 templates_List_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	List<String> list;

	list.addElement("劳逸结合是不错，但也别放松过头。");
	list.addElement("有时明月无人夜，独向昭潭制恶龙。");
	list.addElement("阴阳有序，命运无常，死亡难以预测，却也有它的规矩。");
	list.addElement("律法即是约束，也是工具。");
	list.addElement("赌徒永远会把希望寄托在下一颗骰子上，但最后赚钱的，当然是从来不碰骰子的庄家。");

	list.paintAllElements();

	list[4] = "世界？？？？遗忘我？？";
	list.paintAllElements();

	list.deleteElement(0);
	list.paintAllElements();

	list.addElement("劳逸结合是不错，但也别放松过头。");
	list.paintAllElements();

	list[4] = "在黎明来临之前，总要有人照亮黑暗。";
	list.paintAllElements();

	list.insertElement(4, "只要不失去你的崇高，整个世界都会为你敞开。");
	list.paintAllElements();

	list.insertElement(4, "在旅途的终点再见吧，去见证一切事物的沉淀。", false);
	list.paintAllElements();

	OS::Printf("程序正常结束。");

	return 0;
}
