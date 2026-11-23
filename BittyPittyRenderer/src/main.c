#include "../include/central.h"
#include <stdio.h>

#define SCREEN_WIDTH 112 // WIDTH OF WINDOW XTERM TERMINUS SIZE 8 1366 * 768
#define SCREEN_HEIGHT 55 // HEIGHT OF WINDOW XTERM TERMINUS SIZE 8 1366 * 768

int main(void) {
    Window* w = createWindow(SCREEN_WIDTH, SCREEN_HEIGHT, '.');

    if (w == NULL) {
        return 1;
    }

    int halfX = roundf((float) SCREEN_WIDTH / 2);
    int halfY = roundf((float) SCREEN_HEIGHT / 2);

    clearTerminal();

    Triangle2d t1;
    t1.vertices[0] = (Vector2d) {halfX - 10, halfY + 10};
    t1.vertices[1] = (Vector2d) {halfX + 10, halfY + 10};
    t1.vertices[2] = (Vector2d) {halfX - 10, halfY - 10};

    t1.symbol = '#';

    Triangle2d t2;
    t2.vertices[0] = (Vector2d) {halfX + 10, halfY + 10};
    t2.vertices[1] = (Vector2d) {halfX - 10, halfY - 10};
    t2.vertices[2] = (Vector2d) {halfX + 10, halfY - 10};
    
    t2.symbol = '#';

    while(1) {
        resetCursorPos();
        resetWindow(w, w->resetSymbol);

        setTriangleT(w, t1);
        setTriangleT(w, t2);
        
        drawWindow(w);
        waitNextFrame(30);
    }

    destroyWindow(w);
    return 0;
}
