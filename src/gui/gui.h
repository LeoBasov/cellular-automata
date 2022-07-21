#pragma once

#include <GL/glut.h>
#include <iostream>

#include "../grid/grid.h"
#include "../util/random.h"
#include "../util/timer.h"

namespace ca {

class GUI {
   public:
    static Grid grid_;
    static Random random_;

   public:
    GUI();
    ~GUI() = default;

    static void DrawGrid(void);
    static void DrawCell(const Pair& coords);

    static void SpecialFunc(int key, int x, int y);
    static void KeyboardFunc(unsigned char key, int x, int y);
    static void TimerFunc(int);

    void Run(int argc, char** argv);

   private:
    Timer timer_;
};

// Grid GUI::grid_ = Grid(1, 2);

}  // namespace ca
