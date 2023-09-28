#include "puzzle.hpp"

int main(int argc, char** argv)
{
    auto p = std::unique_ptr<Puzzle>(new Puzzle());
    p->run();
    return 0;
}
