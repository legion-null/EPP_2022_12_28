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

u32 InputDevice::getReportingFrequency() const {
	return this->reportingFrequency;
}

void InputDevice::setReportingFrequency(u32 frequency) {
	this->reportingFrequency = frequency;
}

void InputDevice::wait() {
	Thread::USleep(1000000 / this->reportingFrequency);
}

void InputDevice::run() {
	while (true) {
		try {
			InputEvent *e = reportInputEvent();
			this->eventQueue.enqueue(e);
		} catch (Exception &exception) {
			; // 什么也不做
		}
		wait();
	}
}

bool InputDevice::isInputEventReady() {
	return !(this->eventQueue.isEmpty());
}

const InputEvent& InputDevice::getInputEvent() {
	if (this->isInputEventReady() == false) {
		throw Exception("EventQueue is empty!");
	}

	return *(this->eventQueue.dequeue());
}



}
}
