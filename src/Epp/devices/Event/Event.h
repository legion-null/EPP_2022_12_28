#pragma once

#include "base/Event/Event.h"

namespace Epp {
namespace devices {

class Event: public base::Event {

EPP_CLASS_INFO

public:
	Event();
	virtual ~Event();

};

}
}

