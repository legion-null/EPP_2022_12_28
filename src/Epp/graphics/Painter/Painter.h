#pragma once

#include "base/Object/Object.h"

E_init

namespace Epp {
namespace graphics {

E_import_class(Layer)
E_import_class(Font)
E_import_class(Image)
E_import_class(Rect2D)

class Painter: extends base::Object {

E_CLASS_DEC(Painter,base::Object)

public:
	enum Type : i8 {
		Software = 0,	// 软件实现
		OpenGL = 1,		// OpenGL实现
	};

private:
	EPainter real = nullptr;

protected:
	ELayer layer = nullptr;
	EColor color = nullptr;
	EFont font = nullptr;

public:
	Painter();
	virtual void destroy() override;

public:
	ELayer getLayer();
	void setLayer(ELayer layer);

public:
	EColor getColor();
	void setColor(EColor color);

public:
	void drawPixel(i32 x, i32 y);
	EColor getPixel(i32 x, i32 y);

public:
	EFont getFont();
	void setFont(EFont font);

public:
	virtual void drawLine(i32 x0, i32 y0, i32 x1, i32 y1);
	virtual void drawRect(i32 x0, i32 y0, i32 w, i32 h);
	virtual void drawTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2);
	virtual void drawPolyline(i32 *x, i32 *y, i32 n);
	virtual void drawPolygon(i32 *x, i32 *y, i32 n);
	virtual void drawArc(i32 x, i32 y, i32 w, i32 h, i32 startAngle, i32 endAngle);
	virtual void drawArc(i32 x, i32 y, i32 r, i32 startAngle, i32 endAngle);
	virtual void drawSector(i32 x, i32 y, i32 w, i32 h, i32 startAngle, i32 endAngle);
	virtual void drawSector(i32 x, i32 y, i32 r, i32 startAngle, i32 endAngle);
	virtual void drawOval(i32 x, i32 y, i32 w, i32 h);
	virtual void drawCircle(i32 x, i32 y, i32 r);
	virtual void drawRoundedRect(i32 x, i32 y, i32 w, i32 h, i32 r);

public:
	virtual void fillRect(i32 x, i32 y, i32 w, i32 h);
	virtual void fillTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2);
	virtual void fillPolygon(i32 *x, i32 *y, i32 n);
	virtual void fillSector(i32 x, i32 y, i32 w, i32 h, f64 startAngle, f64 endAngle);
	virtual void fillOval(i32 x, i32 y, i32 w, i32 h);
	virtual void fillCircle(i32 x, i32 y, i32 r);
	virtual void fillRoundedRect(i32 x, i32 y, i32 w, i32 h, i32 r);

public:
	virtual void drawCharacter(i32 x, i32 y, i32 w, i32 h, i32 c);
	virtual void drawCharacter(ERect2D limitBox, i32 c);

public:
	virtual void drawString(i32 x, i32 y, i32 w, i32 h, base::EString str);
	virtual void drawString(ERect2D limitBox, base::EString str);

public:
	virtual void drawImage(i32 x, i32 y, i32 w, i32 h, EImage img);
	virtual void drawImage(ERect2D limitBox, EImage img);
};

E_class(Painter)

}
}

#include "Software/Painter_Software.h"

