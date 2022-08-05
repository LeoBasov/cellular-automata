#include "gui.h"

namespace ca {

Lenia GUI::lenia_;
Random GUI::random_;
uint GUI::counter_;

GUI::GUI() {
    const uint size = 100;
    Lenia::Config config;

    config.Lenia();

    config.x = size;
    config.y = size;

    counter_ = 100;

    lenia_.SetConfig(config);

    for (size_t x = 0; x < lenia_.size_x() - 0; x++) {
        for (size_t y = 0; y < lenia_.size_y() - 0; y++) {
            lenia_.value(x, y) = 0.0;
        }
    }

    for (size_t x = 30; x < 70; x++) {
        for (size_t y = 30; y < 70; y++) {
            lenia_.value(x, y) = random_.RandomNumber();
        }
    }
}

void GUI::DrawGrid(void) {
    const double X = glutGet(GLUT_WINDOW_WIDTH);
    const double Y = glutGet(GLUT_WINDOW_HEIGHT);
    const double dx = X > Y ? (Y / X) * 2.0 / lenia_.size_x() : 2.0 / lenia_.size_x();
    const double dy = Y > X ? (X / Y) * 2.0 / lenia_.size_y() : 2.0 / lenia_.size_y();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (size_t x = 0; x < lenia_.size_x(); x++) {
        for (size_t y = 0; y < lenia_.size_y(); y++) {
            const double color1 = gui_algorithms::Red(lenia_.value(x, y));
            const double color2 = gui_algorithms::Green(lenia_.value(x, y));
            const double color3 = gui_algorithms::Blue(lenia_.value(x, y));
            const double x__ = x * dx - 1.0;
            const double y__ = y * dy - 1.0;

            glBegin(GL_POLYGON);
            {  // GL_POLYGON GL_LINE_LOOP
                glColor3f(color1, color2, color3);

                glVertex3f(x__, y__, 0.0);
                glVertex3f(x__ + dx, y__, 0.0);
                glVertex3f(x__ + dx, y__ + dy, 0.0);
                glVertex3f(x__, y__ + dy, 0.0);
            }
            glEnd();
        }
    }

    // glFlush();
    glutSwapBuffers();
}

void GUI::SpecialFunc(int key, int x, int y) { std::cout << key << std::endl; }

void GUI::KeyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
        case 'r': {
            for (size_t x = 0; x < lenia_.size_x(); x++) {
                for (size_t y = 0; y < lenia_.size_y(); y++) {
                    lenia_.value(x, y) = random_.RandomNumber();
                }
            }

            // glutPostRedisplay();

            break;
        }
        case 'o': {
            for (size_t x = 0; x < lenia_.size_x() - 0; x++) {
                for (size_t y = 0; y < lenia_.size_y() - 0; y++) {
                    lenia_.value(x, y) = 0.0;
                }
            }

            for (size_t x = 30; x < 70; x++) {
                for (size_t y = 30; y < 70; y++) {
                    lenia_.value(x, y) = random_.RandomNumber();
                }
            }
            break;
        }
    }
}

void GUI::TimerFunc(int) {
    lenia_.Process();

    glutPostRedisplay();
    glutTimerFunc(counter_, TimerFunc, 0);
}

void GUI::Run(int argc, char **argv) {
    timer_.Start();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL | GLUT_DOUBLE);
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
