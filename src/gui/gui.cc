#include "gui.h"

namespace ca {

Grid GUI::grid1_;
Grid GUI::grid2_;
Random GUI::random_;
uint GUI::counter_;

GUI::GUI() {
    const uint size = 50;

    counter_ = 100;

    grid1_ = Grid(size, size);
    grid2_ = Grid(size, size);
    grid1_.active_ = true;

    for (size_t x = 0; x < grid1_.size_x(); x++) {
        for (size_t y = 0; y < grid1_.size_y(); y++) {
            grid1_.value(x, y) = std::round(random_.RandomNumber());
        }
    }
}

void GUI::DrawGrid(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (grid1_.active_) {
        for (size_t x = 0; x < grid1_.size_x(); x++) {
            for (size_t y = 0; y < grid1_.size_y(); y++) {
                DrawCell(grid1_, x, y);
            }
        }
    } else {
        for (size_t x = 0; x < grid1_.size_x(); x++) {
            for (size_t y = 0; y < grid1_.size_y(); y++) {
                DrawCell(grid2_, x, y);
            }
        }
    }

    glFlush();
}

void GUI::DrawCell(const Grid &grid, int x, int y) {
    const double dx = 0.9 / grid.size_x();
    const double width = glutGet(GLUT_WINDOW_WIDTH);
    const double height = glutGet(GLUT_WINDOW_HEIGHT);
    const double dy = dx * width / height;
    const double color1 = 255;
    const double color2 = 0 + !grid.value(x, y) * 255;
    const double color3 = 0 + !grid.value(x, y) * 255;

    const double x__ = dx * (2 * x) + dx - 0.9;
    const double y__ = dy * (2 * y) + dy - 0.9;

    glBegin(GL_POLYGON);
    {  // GL_POLYGON GL_LINE_LOOP
        glColor3f(color1, color2, color3);

        glVertex3f(x__ - dx, y__ - dy, 0.0);
        glVertex3f(x__ + dx, y__ - dy, 0.0);
        glVertex3f(x__ + dx, y__ + dy, 0.0);
        glVertex3f(x__ - dx, y__ + dy, 0.0);
    }
    glEnd();

    glBegin(GL_LINE_LOOP);
    {  // GL_POLYGON GL_LINE_LOOP
        glColor3f(0, 0, 0);

        glVertex3f(x__ - dx, y__ - dy, 0.0);
        glVertex3f(x__ + dx, y__ - dy, 0.0);
        glVertex3f(x__ + dx, y__ + dy, 0.0);
        glVertex3f(x__ - dx, y__ + dy, 0.0);
    }
    glEnd();
}

void GUI::SpecialFunc(int key, int x, int y) { std::cout << key << std::endl; }

void GUI::KeyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
        case 'r': {
            /*for (uint i = 0; i < grid1_.size(); i++) {
                grid1_.value(i) = random_.RandomNumber();
            }*/

            glutPostRedisplay();

            break;
        }
    }
}

void GUI::TimerFunc(int) {
    game_of_life::Process(grid2_, grid1_);

    glutPostRedisplay();
    glutTimerFunc(counter_, TimerFunc, 0);
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

    glutTimerFunc(counter_, TimerFunc, 0);

    glutMainLoop();
}

}  // namespace ca
