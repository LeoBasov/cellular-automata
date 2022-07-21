#pragma once

#include <GL/glut.h>

namespace ca {

class GUI {
   public:
    GUI();
    ~GUI() = default;

    static void displayMe(void);
    void Run(int argc, char** argv);
};

}  // namespace ca
