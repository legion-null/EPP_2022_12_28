#pragma once

#include "base/Object/Object.h"

#include "base/Runnable/Runnable.h"

#include "templates/Queue/Queue.hpp"

namespace Epp {
namespace gui {

class InputDevice: virtual public base::Object, virtual public base::Runnable {

EPP_CLASS_INFO

protected:
	templates::Queue<InputEvent*> eventQueue;
	u32 reportingFrequency = 10;	// 报告频率，即每秒报告多少次事件（如果事件全部发生的话）

public:
	InputDevice();
	virtual ~InputDevice();

public:
	u32 getReportingFrequency() const;
	void setReportingFrequency(u32 frequency);

private:
	void wait();

public:
	virtual void run() override;

protected:
	virtual InputEvent* reportInputEvent() = 0;

public:
	bool isInputEventReady();
	const InputEvent& getInputEvent();
};

}
}

#include "KeyBoard/KeyBoard.h"
#include "Mouse/Mouse.h"
#include "TouchPad/TouchPad.h"

