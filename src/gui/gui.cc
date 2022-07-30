#include "gui.h"

namespace ca {

Grid GUI::grid1_;
Grid GUI::grid2_;
Random GUI::random_;
uint GUI::counter_;

GUI::GUI() {
    const uint size = 100;

    counter_ = 100;

    grid1_ = Grid(size, size);
    grid2_ = Grid(size, size);
    grid1_.active_ = true;

    for (uint i = 0; i < grid1_.size(); i++) {
        grid1_.value(i) = std::round(random_.RandomNumber());
    }
}

void GUI::DrawGrid(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (uint i = 0; i < grid1_.size(); i++) {
        if (grid1_.active_) {
            DrawCell(grid1_, i);
        } else {
            DrawCell(grid2_, i);
        }
    }

    glFlush();
}

void GUI::DrawCell(const Grid &grid, const uint &idx) {
    const Pair coords = grid1_.coords(idx);
    const double dx = 0.9 / grid.x();
    const double width = glutGet(GLUT_WINDOW_WIDTH);
    const double height = glutGet(GLUT_WINDOW_HEIGHT);
    const double dy = dx * width / height;
    const double x = dx * (2 * coords.first) + dx - 0.9;
    const double y = dy * (2 * coords.second) + dy - 0.9;
    double color1 = 255;
    double color2 = 0;
    double color3 = 0;

    if (grid.value(coords) > 0.5) {
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
            for (uint i = 0; i < grid1_.size(); i++) {
                grid1_.value(i) = random_.RandomNumber();
            }

            glutPostRedisplay();

            break;
        }
    }
}

void GUI::TimerFunc(int) {
    if (grid1_.active_) {
#pragma omp parallel for
        for (uint i = 0; i < grid1_.size(); i++) {
            game_of_life::Process(grid1_, grid2_, i);
        }

        grid1_.active_ = false;
        grid2_.active_ = true;
    } else {
#pragma omp parallel for
        for (uint i = 0; i < grid2_.size(); i++) {
            game_of_life::Process(grid2_, grid1_, i);
        }

        grid2_.active_ = false;
        grid1_.active_ = true;
    }

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
