#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::templates;

i32 templates_Queue_test_main(i32 argc, c8 **argv) {
	(void) argc;
	(void) argv;

	Queue<String> container;

	container.enqueue("劳逸结合是不错，但也别放松过头。");
	container.enqueue("有时明月无人夜，独向昭潭制恶龙。");
	container.enqueue("阴阳有序，命运无常，死亡难以预测，却也有它的规矩。");
	container.enqueue("律法即是约束，也是工具。");
	container.enqueue("赌徒永远会把希望寄托在下一颗骰子上，但最后赚钱的，当然是从来不碰骰子的庄家。");

	container.paintAllElements();

	container[4] = "世界？？？？遗忘我？？";
	container.paintAllElements();

	container.dequeue();
	container.paintAllElements();

	container.enqueue("劳逸结合是不错，但也别放松过头。");
	container.paintAllElements();

	container[4] = "在黎明来临之前，总要有人照亮黑暗。";
	container.paintAllElements();

	container.enqueue("只要不失去你的崇高，整个世界都会为你敞开。");
	container.paintAllElements();

	container.enqueue("在旅途的终点再见吧，去见证一切事物的沉淀。");
	container.paintAllElements();

	OS::Printf("程序正常结束。");

	return 0;
}
