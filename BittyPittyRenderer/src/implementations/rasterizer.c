#include "../../include/central.h"

void setPixel(Window* w, uint16_t x, uint16_t y, char symbol) {
    w->framebuffer[y * w->width + x] = symbol;
}

void setPixelV(Window* w, Vector2d v, char symbol) {
    w->framebuffer[v.y * w->width + v.x] = symbol;
}

void setLine(Window* w, Vector2d v1, Vector2d v2, char symbol) {
    int x0 = v1.x;
    int y0 = v1.y;

    int x1 = v2.x;
    int y1 = v2.y;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;

    int error = dx - dy;

    while (1) {
        setPixel(w, x0, y0, symbol);

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * error;

        if (e2 > -dy) {
            error -= dy;
            x0 += sx;
        }

        if (e2 < dx) {
            error += dx;
            y0 += sy;
        }
    }
}

void setLineL(Window* w, Line l) {
    int x0 = l.vertices[0].x;
    int y0 = l.vertices[0].y;

    int x1 = l.vertices[1].x;
    int y1 = l.vertices[1].y;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;

    int error = dx - dy;

    while (1) {
        setPixel(w, x0, y0, l.symbol);

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * error;

        if (e2 > -dy) {
            error -= dy;
            x0 += sx;
        }

        if (e2 < dx) {
            error += dx;
            y0 += sy;
        }
    }
}

void setTriangle(Window* w, Vector2d v1, Vector2d v2, Vector2d v3, char symbol) {
    setLine(w, v1, v2, symbol);
    setLine(w, v2, v3, symbol);
    setLine(w, v3, v1, symbol);
}

void setTriangleT(Window* w, Triangle2d t) {
    setLine(w, t.vertices[0], t.vertices[1], t.symbol);
    setLine(w, t.vertices[1], t.vertices[2], t.symbol);
    setLine(w, t.vertices[2], t.vertices[0], t.symbol);
}
