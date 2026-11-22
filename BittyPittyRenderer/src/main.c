#include "../include/central.h"

int main(void) {
    Window* w = createWindow(67, 32, ' ');

    if (w == NULL) {
        return 1;
    }

    char* string = "Hello world!\n";
    int stringLen = getStringLength(string);

    clearTerminal();

    while(1) {
        resetCursorPos();
        resetWindow(w, w->resetSymbol);

        for (int i = 0; i < stringLen; i++) {
            setPixel(w, i, 1, *charToString(string[i]));
        }

        drawWindow(w);
        waitNextFrame(30);
    }

    destroyWindow(w);
    return 0;
}
