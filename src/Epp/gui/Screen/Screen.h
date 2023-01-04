#pragma once

#include "graphics/Layer/Layer.h"

#include "graphics/Color/Color.h"

namespace Epp {
namespace gui {

class Screen: public graphics::Layer {

EPP_CLASS_INFO

protected:
	static f32 MinPPM;
	static f32 MaxPPM;
	static f32 MinSlightDistance;
	static f32 MaxSlightDistance;

public:
	static Screen* GetDefaultScreen();

protected:
	base::String *title = nullptr;

protected:
	f32 hppm = 0;	// 横向每毫米像素数量（为了防止开发者设置不当，这两项有范围限制）
	f32 vppm = 0;	// 纵向每毫米像素数量（为了防止某些屏幕的像素横纵方向尺度不一致）

	f32 hp = 0;		// 横向像素宽度，单位为mm，根据hppm得出
	f32 vp = 0;		// 纵向像素宽度

protected:
	f32 slightDistance = 20;	// 视距，单位为毫米

protected:
	Layer *display = nullptr;

public:
	Screen();

public:
	Screen(i32 w, i32 h, graphics::Color::Type colorType, graphics::Rot rot);
	Screen(base::String *title, i32 w, i32 h, graphics::Color::Type colorType, graphics::Rot rot);

public:
	base::String* getTitle();
	virtual void setTitle(base::String *title);

public:
	f32 getHPPM() const;
	f32 getVPPM() const;

	void getPPM(f32 &hppm, f32 &vppm) const;

public:
	void setHPPM(f32 hppm);
	void setVPPM(f32 vppm);

	void setPPM(f32 hppm, f32 vppm);

public:

public:
	virtual void refreshRect(i32 x0, i32 y0, i32 w, i32 h);
	virtual void refresh();

public:
	virtual void test();

};

}
}

