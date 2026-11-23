#pragma once

#include "central.h"

typedef struct Vector2d {
    uint16_t x;
    uint16_t y;
} Vector2d;

typedef struct Line2d {
    Vector2d vertices[2];
    char symbol;
} Line;

typedef struct Triangle2d {
    Vector2d vertices[3];
    char symbol;
} Triangle2d;

void setPixel(Window* w, uint16_t x, uint16_t y, char symbol);
void setPixelV(Window* w, Vector2d v, char symbol);

void setLine(Window* w, Vector2d v1, Vector2d v2, char symbol);
void setLineL(Window* w, Line l);

void setTriangle(Window* w, Vector2d v1, Vector2d v2, Vector2d v3, char symbol);
void setTriangleT(Window* w, Triangle2d t);
