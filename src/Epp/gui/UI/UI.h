#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace gui {

class Item;

class UI: public base::Object {

EPP_CLASS_INFO

protected:
	Item *item = nullptr;

public:
	UI();
	virtual ~UI();

};

}
}
