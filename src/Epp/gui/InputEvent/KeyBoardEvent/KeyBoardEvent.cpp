#include "Epp.h"

using namespace Epp::gui;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const Class *KeyBoardEvent::ClassInfo = Class::Register<KeyBoardEvent, InputEvent>("Epp::gui::KeyBoardEvent", nullptr);

KeyBoardEvent::KeyBoardEvent() {

}

KeyBoardEvent::~KeyBoardEvent() {

}

}
}
