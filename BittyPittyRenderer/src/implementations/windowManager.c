#include "../../include/central.h"

Window* createWindow(uint16_t width, uint16_t height, char resetSymbol) {
    Window* w = malloc(sizeof(Window));

    if (w == NULL) {
        return NULL;
    }

    uint16_t maxSize = width * height;

    w->resetSymbol = resetSymbol;

    w->width = width;
    w->height = height;

    w->framebuffer = malloc(sizeof(char) * maxSize);

    if (w->framebuffer == NULL) {
        return NULL;
    }

    memset(w->framebuffer, resetSymbol, sizeof(char) * maxSize);

    return w;
}

void destroyWindow(Window* w) {
    free(w->framebuffer);
    free(w);
}

void resetWindow(Window* w, char resetSymbol) {
    uint16_t maxSize = w->width * w->height;
    memset(w->framebuffer, resetSymbol, sizeof(char) * maxSize);
}

void drawWindow(Window* w) {
    uint16_t maxSize = (w->width * 2 + 1) * w->height;
    char* string = malloc(sizeof(char) * maxSize);

    string[maxSize] = '\0';

    int i = 0;

    for (int y = 0; y < w->height; y++) {
        for (int x = 0; x < w->width; x++) {
            string[i++] = w->framebuffer[y * w->width + x];
            string[i++] = ' ';
        }

        string[i++] = '\n';
    }

    print(string);
    
    free(string);
}

void clearTerminal() {
    print("\033[2J\033[H");
}

void resetCursorPos() {
    print("\033[H");
}

void waitNextFrame(uint16_t FPS) {
    if (FPS == 0) {
        return;
    }

    usleep(1000000 / FPS);
}
