#include "gui.h"

namespace ca {

Grid GUI::grid_;

GUI::GUI() {
    grid_ = Grid(10, 10);
    Random random_;

    for (uint i = 0; i < grid_.size(); i++) {
        grid_.value(i) = random_.RandomNumber();
    }
}

void GUI::DrawGrid(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    for (uint i = 0; i < grid_.size(); i++) {
        DrawCell(grid_.coords(i));
    }

    glFlush();
}

void GUI::DrawCell(const Pair& coords) {
    const double dx = 0.05;
    const double x = dx * (2 * coords.first) + dx - 0.9;
    const double y = dx * (2 * coords.second) + dx - 0.9;
    double color1 = 255;
    double color2 = 0;
    double color3 = 0;

    if (grid_.value(coords) > 0.5) {
        color1 = 255;
        color2 = 0;
        color3 = 0;
    } else {
        color1 = 255;
        color2 = 255;
        color3 = 255;
    }

    glBegin(GL_POLYGON);
    {  // GL_POLYGON GL_LINE_LOOP
        glColor3f(color1, color2, color3);

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
