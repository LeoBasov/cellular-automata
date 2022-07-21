#include "gui.h"

namespace ca {

Grid GUI::grid_;
Random GUI::random_;

GUI::GUI() {
    grid_ = Grid(10, 10);

    for (uint i = 0; i < grid_.size(); i++) {
        grid_.value(i) = random_.RandomNumber();
    }
}

void GUI::DrawGrid(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (uint i = 0; i < grid_.size(); i++) {
        DrawCell(grid_.coords(i));
    }

    glFlush();
}

void GUI::DrawCell(const Pair& coords) {
    const double dx = 0.9 / grid_.x();
    const double width = glutGet(GLUT_WINDOW_WIDTH);
    const double height = glutGet(GLUT_WINDOW_HEIGHT);
    const double dy = dx * width / height;
    const double x = dx * (2 * coords.first) + dx - 0.9;
    const double y = dy * (2 * coords.second) + dy - 0.9;
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

        glVertex3f(x - dx, y - dy, 0.0);
        glVertex3f(x + dx, y - dy, 0.0);
        glVertex3f(x + dx, y + dy, 0.0);
        glVertex3f(x - dx, y + dy, 0.0);
    }
    glEnd();
}

void GUI::SpecialFunc(int key, int x, int y) { std::cout << key << std::endl; }

void GUI::KeyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
        case 'r': {
            for (uint i = 0; i < grid_.size(); i++) {
                grid_.value(i) = random_.RandomNumber();
            }

            glutPostRedisplay();

            break;
        }
    }
}

void GUI::TimerFunc(int) {
    for (uint i = 0; i < grid_.size(); i++) {
        grid_.value(i) = random_.RandomNumber();
    }

    glutPostRedisplay();
    glutTimerFunc(1000, TimerFunc, 0);
}

void GUI::Run(int argc, char **argv) {
    timer_.Start();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(DrawGrid);

    glutSpecialFunc(SpecialFunc);
    glutKeyboardFunc(KeyboardFunc);

    glutTimerFunc(1000, TimerFunc, 0);

    glutMainLoop();
}

}  // namespace ca
