#include "gui.h"

namespace ca {

Grid GUI::grid_ = Grid();

GUI::GUI() { GUI::grid_ = Grid(1, 1); }

void GUI::DrawGrid(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    for (uint i = 0; i < grid_.size(); i++) {
        DrawCell(grid_.Coords(i));
    }

    glFlush();
}

void GUI::DrawCell(const Pair& coords) {
    const double dx = 0.1;
    const double x = dx * (2 * coords.first) + dx;
    const double y = dx * (2 * coords.second) + dx;

    glBegin(GL_LINE_LOOP);
    {  // GL_POLYGON
        glVertex3f(x - dx, y - dx, 0.0);
        glVertex3f(x + dx, y - dx, 0.0);
        glVertex3f(x + dx, y + dx, 0.0);
        glVertex3f(x - dx, y + dx, 0.0);
    }
    glEnd();
}

void GUI::Run(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(DrawGrid);
    glutMainLoop();
}

}  // namespace ca
