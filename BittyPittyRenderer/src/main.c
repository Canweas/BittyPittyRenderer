#include "../include/central.h"

int main(void) {
    Window* w = createWindow(10, 10, '#');

    if (w == NULL) {
        return 1;
    }

    while (1) {
        resetCursorPos();
        resetWindow(w, '.');
        drawWindow(w);

        waitNextFrame(30);
    }

    destroyWindow(w);
    return 0;
}
