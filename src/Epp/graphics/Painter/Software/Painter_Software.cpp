#include "Epp.h"

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace graphics {

const Class *Painter_Software::ClassInfo = Class::Register<Painter_Software, Painter>("Epp::graphics::Painter_Software", nullptr);

void Painter_Software::GetLinePixel(i32 x0, i32 y0, i32 x1, i32 y1, i32 **px, i32 **py, i32 &n) {
	i32 x = x0;
	i32 y = y0;

	if (x0 == x1) {
		// 垂直线
		i32 sy = y1 > y0 ? 1 : -1;
		n = (sy == 1 ? y1 - y0 : y0 - y1) + 1;

		*px = new i32[n]; // 分配内存
		*py = new i32[n]; // 分配内存

		for (i32 i = 1; i < n - 1; i++) {
			y = y + sy;
			(*px)[i] = x;
			(*py)[i] = y;
		}
	} else if (y0 == y1) {
		// 水平线
		i32 sx = x1 > x0 ? 1 : -1;
		n = (sx == 1 ? x1 - x0 : x0 - x1) + 1;

		*px = new i32[n]; // 分配内存
		*py = new i32[n]; // 分配内存

		for (i32 i = 1; i < n - 1; i++) {
			x = x + sx;
			(*px)[i] = x;
			(*py)[i] = y;
		}
	} else {
		// 斜线，Bresenham算法
		i32 sx = x1 > x0 ? 1 : -1;
		i32 sy = y1 > y0 ? 1 : -1;
		i32 dx = (sx == 1 ? x1 - x0 : x0 - x1);
		i32 dy = (sy == 1 ? y1 - y0 : y0 - y1);
		i32 erro = (dx > dy ? dx : -dy) / 2;
		n = (dx > dy ? dx : dy) + 1;

		*px = new i32[n]; // 分配内存
		*py = new i32[n]; // 分配内存

		for (i32 i = 1; i < n - 1; i++) {
			if (erro > -dx) {
				erro = erro - dy;
				x = x + sx;
			}
			if (erro < dy) {
				erro = erro + dx;
				y = y + sy;
			}
			(*px)[i] = x;
			(*py)[i] = y;
		}
	}

	// 首尾两点统一处理
	(*px)[0] = x0;
	(*py)[0] = y0;
	(*px)[n - 1] = x1;
	(*py)[n - 1] = y1;
}

Painter_Software::Painter_Software() :
		Painter_Software(nullptr) {

}

Painter_Software::Painter_Software(const Layer *layer) :
		Painter(layer) {

}

void Painter_Software::drawLine(i32 x0, i32 y0, i32 x1, i32 y1) {
	EPP_FUNC_LOCATE("%d, %d, %d, %d", x0, y0, x1, y1);

	//EPP_DEBUG("%s", "XXX");
	if (x0 == x1) {
		return this->layer->drawLineV(x0, Min(y0, y1), Abs(y1 - y0) + 1, this->color);
	} else if (y0 == y1) {
		//EPP_CODE_LOCATE();
		return this->layer->drawLineH(Min(x0, x1), y0, Abs(x1 - x0) + 1, this->color);
	} else {
		// Bresenham算法
		i32 x = x0;
		i32 y = y0;

		i32 sx = x1 > x0 ? 1 : -1;
		i32 sy = y1 > y0 ? 1 : -1;
		i32 dx = sx == 1 ? x1 - x0 : x0 - x1;
		i32 dy = sy == 1 ? y1 - y0 : y0 - y1;
		i32 erro = (dx > dy ? dx : -dy) / 2;
		i32 n = (dx > dy ? dx : dy) + 1;

		for (i32 i = 1; i < n - 1; i++) {
			if (erro > -dx) {
				erro = erro - dy;
				x = x + sx;
			}
			if (erro < dy) {
				erro = erro + dx;
				y = y + sy;
			}
			drawPixel(x, y);
		}

		// 首尾两点统一处理
		drawPixel(x0, y0);
		drawPixel(x1, y1);
	}
}

void Painter_Software::drawRect(i32 x0, i32 y0, i32 w, i32 h) {
	i32 x1 = x0 + w - 1;
	i32 y1 = y0 + h - 1;

	drawLine(x0, y0, x1, y0);
	drawLine(x0, y0, x0, y1);
	drawLine(x1, y0, x1, y1);
	drawLine(x0, y1, x1, y1);
}

void Painter_Software::drawTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2) {
	drawLine(x0, y0, x1, y1);
	drawLine(x1, y1, x2, y2);
	drawLine(x2, y2, x0, y0);
}

void Painter_Software::drawPolyline(i32 *x, i32 *y, i32 n) {
	for (i32 i = 0; i < n - 1; i++)
		drawLine(x[i], y[i], x[i + 1], y[i + 1]);
}

void Painter_Software::drawPolygon(i32 *x, i32 *y, i32 n) {
	drawPolyline(x, y, n);
	drawLine(x[0], y[0], x[n - 1], y[n - 1]);
}

void Painter_Software::drawArc(i32 x, i32 y, i32 w, i32 h, i32 startAngle, i32 endAngle) {
	(void) x;
	(void) y;
	(void) w;
	(void) h;
	(void) startAngle;
	(void) endAngle;
}

void Painter_Software::drawArc(i32 x, i32 y, i32 r, i32 startAngle, i32 endAngle) {
	return drawArc(x, y, r * 2, r * 2, startAngle, endAngle);
}

void Painter_Software::drawSector(i32 x, i32 y, i32 w, i32 h, i32 startAngle, i32 endAngle) {
	(void) x;
	(void) y;
	(void) w;
	(void) h;
	(void) startAngle;
	(void) endAngle;
}

void Painter_Software::drawSector(i32 x, i32 y, i32 r, i32 startAngle, i32 endAngle) {
	return drawSector(x, y, r * 2, r * 2, startAngle, endAngle);
}

void Painter_Software::drawOval(i32 x0, i32 y0, i32 w, i32 h) {
	if (w > h) {	// 焦点纵坐标相同的椭圆
		i32 a = w / 2;
		i32 b = h / 2;
		i32 a2 = a * a;
		i32 b2 = b * b;
		i32 basis = a2 * b2;
		i32 dx = a;
		i32 dy = 0;

		x0 = x0 + a;
		y0 = y0 + b;

		while (dy <= b && dx >= 0) {
			drawPixel(x0 + dx, y0 + dy);	//   0 pi ~ 1/2 pi
			drawPixel(x0 - dx, y0 + dy);	// 1/2 pi ~   1 pi
			drawPixel(x0 - dx, y0 - dy);	//   1 pi ~ 3/2 pi
			drawPixel(x0 + dx, y0 - dy);	// 3/2 pi ~   2 pi

			dx = dx - 1;
			dy = dy + 1;

			if (b2 * dx * dx + a2 * dy * dy <= basis)
				dx = dx + 1;
			else
				dy = dy - 1;
		}
	} else {	// 焦点横坐标相同的椭圆
		i32 a = h / 2;
		i32 b = w / 2;
		i32 a2 = a * a;
		i32 b2 = b * b;
		i32 basis = a2 * b2;
		i32 dy = a;
		i32 dx = 0;

		x0 = x0 + b;
		y0 = y0 + a;

		while (dx <= b && dy >= 0) {
			drawPixel(x0 + dx, y0 - dy);	//   0 pi ~ 1/2 pi
			drawPixel(x0 - dx, y0 - dy);	// 1/2 pi ~   1 pi
			drawPixel(x0 - dx, y0 + dy);	//   1 pi ~ 3/2 pi
			drawPixel(x0 + dx, y0 + dy);	// 3/2 pi ~   2 pi

			dy = dy - 1;
			dx = dx + 1;

			if (a2 * dx * dx + b2 * dy * dy <= basis)
				dy = dy + 1;
			else
				dx = dx - 1;
		}
	}
}

void Painter_Software::drawCircle(i32 x, i32 y, i32 r) {
	return drawOval(x - r, y - r, 2 * r, 2 * r);
}

void Painter_Software::drawRoundedRect(i32 x, i32 y, i32 w, i32 h, i32 r) {
	(void) x;
	(void) y;
	(void) w;
	(void) h;
	(void) r;
}

void Painter_Software::fillRect(i32 x0, i32 y0, i32 w, i32 h) {
	EPP_CODE_LOCATE();
	i32 x1 = x0 + w - 1;
	i32 y1 = y0 + h - 1;
	for (i32 y = y0; y <= y1; y++)
		drawLine(x0, y, x1, y);
}

void Painter_Software::fillTriangle(i32 x0, i32 y0, i32 x1, i32 y1, i32 x2, i32 y2) {
	i32 startX = x0;
	i32 startY = y0;
	i32 midX = x0;
	i32 midY = y0;
	i32 endX = x0;
	i32 endY = y0;

	i32 *start2midX = nullptr;
	i32 *start2midY = nullptr;
	i32 *mid2endX = nullptr;
	i32 *mid2endY = nullptr;
	i32 *start2EndX = nullptr;
	i32 *start2EndY = nullptr;

	i32 start2midN = 0;
	i32 mid2endN = 0;
	i32 start2endN = 0;

	// 自顶向下水平渲染，先根据y坐标对点进行排序
	// 最顶端点
	if (startY > y1) {
		startY = y1;
		startX = x1;
		if (startY > y2) {
			startY = y2;
			startX = x2;
		}
	} else if (startY > y2) {
		startY = y2;
		startX = x2;
	}
	// 最底端点
	if (endY < y1) {
		endY = y1;
		endX = x1;
		if (endY < y2) {
			endY = y2;
			endX = x2;
		}
	} else if (endY < y2) {
		endY = y2;
		endX = x2;
	}

	// 中间端点
	midX = x0 + x1 + x2 - startX - endX;
	midY = y0 + y1 + y2 - startY - endY;

	// 边框渲染
	GetLinePixel(startX, startY, midX, midY, &start2midX, &start2midY, start2midN);
	GetLinePixel(midX, midY, endX, endY, &mid2endX, &mid2endY, mid2endN);
	GetLinePixel(startX, startY, endX, endY, &start2EndX, &start2EndY, start2endN);

	drawLine(startX, startY, midX, midY);
	drawLine(midX, midY, endX, endY);
	drawLine(startX, startY, endX, endY);

	// 内部渲染
	i32 i = 0; // 作为lineStart2End下标
	i32 j = 0; // 作为lineStart2Mid、lineMid2End下标
	if (startY != midY)
		for (i32 y = startY; y <= midY; y++) {
			while (start2EndY[i] != y)
				i++;
			while (start2midY[j] != y)
				j++;
			drawLine(start2EndX[i], y, start2midX[j], y);
		}

	j = 0;
	if (midY != endY)
		for (i32 y = midY; y <= endY; y++) {
			while (start2EndY[i] != y)
				i++;
			while (mid2endY[j] != y)
				j++;
			drawLine(start2EndX[i], y, mid2endX[j], y);
		}

	// 释放内存
	delete[] start2midX;
	delete[] start2midY;
	delete[] mid2endX;
	delete[] mid2endY;
	delete[] start2EndX;
	delete[] start2EndY;
}

void Painter_Software::fillPolygon(i32 *x, i32 *y, i32 n) {
	// 暂时使用
	for (i32 i = 0; i < n - 1; i++)
		fillTriangle(x[0], y[0], x[i], y[i], x[i + 1], y[i + 1]);
}

void Painter_Software::fillSector(i32 x, i32 y, i32 w, i32 h, f64 startAngle, f64 endAngle) {
	(void) x;
	(void) y;
	(void) w;
	(void) h;
	(void) startAngle;
	(void) endAngle;
}

void Painter_Software::fillOval(i32 x0, i32 y0, i32 w, i32 h) {
	if (w > h) {	// 焦点纵坐标相同的椭圆
		i32 a = w / 2;
		i32 b = h / 2;
		i32 a2 = a * a;
		i32 b2 = b * b;
		i32 basis = a2 * b2;
		i32 dx = a;
		i32 dy = 0;

		x0 = x0 + a;
		y0 = y0 + b;

		while (dy <= b && dx >= 0) {
			drawLine(x0 + dx, y0 + dy, x0 - dx, y0 + dy);	//   0 pi ~   1 pi
			drawLine(x0 + dx, y0 - dy, x0 - dx, y0 - dy);	//   1 pi ~   2 pi

			dx = dx - 1;
			dy = dy + 1;

			if (b2 * dx * dx + a2 * dy * dy <= basis)
				dx = dx + 1;
			else
				dy = dy - 1;
		}
	} else {	// 焦点横坐标相同的椭圆
		i32 a = h / 2;
		i32 b = w / 2;
		i32 a2 = a * a;
		i32 b2 = b * b;
		i32 basis = a2 * b2;
		i32 dy = a;
		i32 dx = 0;

		x0 = x0 + b;
		y0 = y0 + a;

		while (dx <= b && dy >= 0) {
			drawLine(x0 + dx, y0 + dy, x0 - dx, y0 + dy);	//   0 pi ~   1 pi
			drawLine(x0 + dx, y0 - dy, x0 - dx, y0 - dy);	//   1 pi ~   2 pi

			dy = dy - 1;
			dx = dx + 1;

			if (a2 * dx * dx + b2 * dy * dy <= basis)
				dy = dy + 1;
			else
				dx = dx - 1;
		}
	}
}

void Painter_Software::fillCircle(i32 x, i32 y, i32 r) {
	(void) x;
	(void) y;
	(void) r;
}

void Painter_Software::fillRoundedRect(i32 x, i32 y, i32 w, i32 h, i32 r) {
	(void) x;
	(void) y;
	(void) w;
	(void) h;
	(void) r;
}

}
}
