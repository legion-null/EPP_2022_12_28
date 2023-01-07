#include "Epp.h"

using namespace Epp::gui;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace gui {

const Class *KeyBoard::ClassInfo = Class::Register<KeyBoard, InputDevice>("Epp::gui::KeyBoard", nullptr);

KeyBoard::KeyBoard() {

}

KeyBoard::~KeyBoard() {

}

}
}
