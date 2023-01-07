#include "Epp.h"

using namespace Epp::gui;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const Class *InputDevice::ClassInfo = Class::Register<InputDevice, Object>("Epp::gui::InputDevice", nullptr);

InputDevice::InputDevice() {

}

InputDevice::~InputDevice() {

}

void InputDevice::wait() {
	Thread::Sleep(1);
}

void InputDevice::run() {
	InputEvent *e = nullptr;
	while (true) {
		e = reportInputEvent();
		if (e != nullptr) {
			this->eventQueue.enqueue(e);
		}
		wait();
	}
}

bool InputDevice::isInputEventReady() {
	return true;
}

InputEvent* InputDevice::getInputEvent() {
	return nullptr;
}

}
}
