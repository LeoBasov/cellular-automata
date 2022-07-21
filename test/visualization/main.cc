#include <GL/glut.h>

#include "../../src/gui/gui.h"

int main(int argc, char** argv) {
    ca::GUI gui;

    gui.Run(argc, argv);

    return 0;
}
