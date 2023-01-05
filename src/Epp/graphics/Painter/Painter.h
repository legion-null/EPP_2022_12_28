#pragma once

#include "graphics/graphics/graphics.hpp"

#include "base/Object/Object.h"

#include "graphics/Color/Color.h"

namespace Epp {
namespace graphics {

class Layer;
class Color;
class Font;
class Image;
class Rect2D;

class Painter: public Epp::base::Object {

EPP_CLASS_INFO

public:
	enum IMType : i8 {
		OpenGL,			// OpenGL实现
		Software,		// 软件实现
	};

public:
	static const c8* GetEnumType(IMType e);

protected:
	static const i32 NumberOfIM = 2;
	static const bool ValidityOfIM[NumberOfIM];

public:
	static bool IsAvailable(IMType type);

protected:
	static IMType DefaultIMType;
	static IMType InitDefaultIMType();

public:
	static IMType GetDefaultIMType();
	static void SetDefaultIMType(IMType type);

public:
	static Painter* GetIM(IMType type);
	static Painter* GetDefaultIM();

protected:
	Layer *layer = nullptr;
	Color *color = C(Black);
	Font *font = new Font();

public:
	Painter();

public:
	Painter(Layer *layer);

public:
	const Layer* getLayer() const;
	void setLayer(Layer *layer);

public:
	Color* getColor();
	void setColor(Color *color);

public:
	void drawPixel(i32 x, i32 y);
	Color* getPixel(i32 x, i32 y);

public:
	Font* getFont();
	void setFont(Font *font);

public:
	virtual void drawLine(i32 x0, i32 y0, i32 x1, i32 y1) = 0;
	virtual void drawRect(i32 x0, i32 y0, i32 w, i32 h) = 0;
	virtual void drawTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2) = 0;
	virtual void drawPolyline(i32 *x, i32 *y, i32 n) = 0;
	virtual void drawPolygon(i32 *x, i32 *y, i32 n) = 0;
	virtual void drawArc(i32 x, i32 y, i32 w, i32 h, i32 startAngle, i32 endAngle) = 0;
	virtual void drawArc(i32 x, i32 y, i32 r, i32 startAngle, i32 endAngle) = 0;
	virtual void drawSector(i32 x, i32 y, i32 w, i32 h, i32 startAngle, i32 endAngle) = 0;
	virtual void drawSector(i32 x, i32 y, i32 r, i32 startAngle, i32 endAngle) = 0;
	virtual void drawOval(i32 x, i32 y, i32 w, i32 h) = 0;
	virtual void drawCircle(i32 x, i32 y, i32 r) = 0;
	virtual void drawRoundedRect(i32 x, i32 y, i32 w, i32 h, i32 r) = 0;

public:
	virtual void fillRect(i32 x, i32 y, i32 w, i32 h) = 0;
	virtual void fillTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2) = 0;
	virtual void fillPolygon(i32 *x, i32 *y, i32 n) = 0;
	virtual void fillSector(i32 x, i32 y, i32 w, i32 h, f64 startAngle, f64 endAngle) = 0;
	virtual void fillOval(i32 x, i32 y, i32 w, i32 h) = 0;
	virtual void fillCircle(i32 x, i32 y, i32 r) = 0;
	virtual void fillRoundedRect(i32 x, i32 y, i32 w, i32 h, i32 r) = 0;

public:
	virtual void drawCharacter(i32 x, i32 y, i32 w, i32 h, i32 c);

public:
	virtual void drawString(i32 x, i32 y, i32 w, i32 h, base::String *str);

public:
	virtual void drawImage(i32 x, i32 y, i32 w, i32 h, Image *img);
};

}
}

#include "Software/Painter_Software.h"
#include "OpenGL/Painter_OpenGL.h"
