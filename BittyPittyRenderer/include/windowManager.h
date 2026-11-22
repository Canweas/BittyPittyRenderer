#pragma once

#include "central.h"

typedef struct Window {
    uint16_t width;
    uint16_t height;

    char resetSymbol;
    char* framebuffer;
} Window;

Window* createWindow(uint16_t width, uint16_t height, char resetSymbol);
void destroyWindow(Window* w);

void resetWindow(Window* w, char resetSymbol);
void drawWindow(Window* w);

void clearTerminal();

void resetCursorPos();
void waitNextFrame(uint16_t FPS);

