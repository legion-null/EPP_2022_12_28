#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

using namespace Epp::graphics;

namespace Epp {
namespace gui {

const Class *Screen::ClassInfo = Class::Register<Screen, Layer>("Epp::gui::Screen", nullptr);

f32 Screen::MinPPM = 1e-3;		// 最小PPM默认为0.001，相当于像素长度1m
f32 Screen::MaxPPM = 1e3;		// 最大PPM默认为1000
f32 Screen::MinSlightDistance = 1e2;	// 最小视距默认为10mm
f32 Screen::MaxSlightDistance = 3e7;	// 最大视距默认为30km

Screen* Screen::GetDefaultScreen() {
	EPP_CODE_LOCATE();
	return GUIService::GetDefaultIM()->getScreen();
}

Screen::Screen() {

}

Screen::Screen(i32 w, i32 h, Color::Type colorType, Rot rot) :
		Layer(w, h, colorType, rot) {
}

Screen::Screen(const base::String& title, i32 w, i32 h, graphics::Color::Type colorType, graphics::Rot rot) :
		Layer(w, h, colorType, rot) {
}

const String& Screen::getTitle() const {
	return *(this->title);
}

void Screen::setTitle(const String& title) {
	SafeDelete(this->title);
	this->title = new String(title);
}

f32 Screen::getHPPM() const {
	return this->hppm;
}

f32 Screen::getVPPM() const {
	return this->vppm;
}

void Screen::getPPM(f32 &hppm, f32 &vppm) const {
	hppm = getHPPM();
	vppm = getVPPM();
}

void Screen::setHPPM(f32 hppm) {
	if (hppm < MinPPM) {
		throw new Exception("HPPM过低！");
	} else if (hppm > MaxPPM) {
		throw new Exception("HPPM过高！");
	}

	this->hppm = hppm;
}

void Screen::setVPPM(f32 vppm) {
	if (vppm < MinPPM) {
		throw new Exception("VPPM过低！");
	} else if (vppm > MaxPPM) {
		throw new Exception("VPPM过高！");
	}

	this->vppm = vppm;
}

void Screen::setPPM(f32 hppm, f32 vppm) {
	if (hppm < MinPPM) {
		throw new Exception("HPPM过低！");
	} else if (hppm > MaxPPM) {
		throw new Exception("HPPM过高！");
	} else if (vppm < MinPPM) {
		throw new Exception("VPPM过低！");
	} else if (vppm > MaxPPM) {
		throw new Exception("VPPM过高！");
	}

	this->hppm = hppm;
	this->vppm = vppm;
}

void Screen::refreshRect(i32 x0, i32 y0, i32 w, i32 h) {
	rMapPixel(x0, y0);
	this->display->copyFrom(this, x0, y0, w, h, x0, y0);
}

void Screen::refresh() {
	this->display->copyFrom(this);
}

void Screen::test() {
	static Color testColor[7] = { Color::Red, Color::Orange, Color::Yellow, Color::Green, Color::Cyan, Color::Blue, Color::Purple };

	for (i32 i = 0;; i++) {
		Layer::clear(testColor[i % 7]);

//		for (i32 sideLength = 100, y = 0; y + sideLength <= this->h; y += sideLength) {
//			for (i32 x = 0; x + sideLength <= this->w; x += sideLength) {
//				if (i % 2 == 0 and Diff(x, y) % (2 * sideLength) == 0) {
//					refreshRect(x, y, sideLength, sideLength);
//				} else if (i % 2 == 1 and Diff(x, y) % (2 * sideLength) == sideLength) {
//					refreshRect(x, y, sideLength, sideLength);
//				}
//			}
//		}
		refresh();
		Thread::Sleep(1);
	}
}

}
}
