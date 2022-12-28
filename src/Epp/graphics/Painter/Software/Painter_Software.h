#pragma once

#include "graphics/Painter/Painter.h"

E_init

namespace Epp {
namespace graphics {

class Painter_Software: extends Painter {

E_CLASS_DEC(Painter_Software,Painter)

public:
	static void GetLinePixel(i32 x0, i32 y0, i32 x1, i32 y1, i32 **px, i32 **py, i32 &n);

public:
	Painter_Software();
	virtual void destroy() override;

public:
	virtual void drawLine(i32 x0, i32 y0, i32 x1, i32 y1) override;
	virtual void drawRect(i32 x0, i32 y0, i32 w, i32 h) override;
	virtual void drawTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2) override;
	virtual void drawPolyline(i32 *x, i32 *y, i32 n) override;
	virtual void drawPolygon(i32 *x, i32 *y, i32 n) override;
	virtual void drawArc(i32 x, i32 y, i32 w, i32 h, i32 startAngle, i32 endAngle) override;
	virtual void drawArc(i32 x, i32 y, i32 r, i32 startAngle, i32 endAngle) override;
	virtual void drawSector(i32 x, i32 y, i32 w, i32 h, i32 startAngle, i32 endAngle) override;
	virtual void drawSector(i32 x, i32 y, i32 r, i32 startAngle, i32 endAngle) override;
	virtual void drawOval(i32 x, i32 y, i32 w, i32 h) override;
	virtual void drawCircle(i32 x, i32 y, i32 r) override;
	virtual void drawRoundedRect(i32 x, i32 y, i32 w, i32 h, i32 r) override;

public:
	virtual void fillRect(i32 x, i32 y, i32 w, i32 h) override;
	virtual void fillTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2) override;
	virtual void fillPolygon(i32 *x, i32 *y, i32 n) override;
	virtual void fillSector(i32 x, i32 y, i32 w, i32 h, f64 startAngle, f64 endAngle) override;
	virtual void fillOval(i32 x, i32 y, i32 w, i32 h) override;
	virtual void fillCircle(i32 x, i32 y, i32 r) override;
	virtual void fillRoundedRect(i32 x, i32 y, i32 w, i32 h, i32 r) override;

};

E_class(Painter_Software)

}
}

