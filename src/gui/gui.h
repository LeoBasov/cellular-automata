#pragma once

#include <GL/glut.h>

#include "../grid/grid.h"

namespace ca {

class GUI {
   public:
    static Grid grid_;

   public:
    GUI();
    ~GUI() = default;

    static void DrawGrid(void);
    static void DrawCell(const Pair& coords);

    void Run(int argc, char** argv);
};

// Grid GUI::grid_ = Grid(1, 2);

}  // namespace ca
