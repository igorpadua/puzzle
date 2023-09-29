#include "puzzle.hpp"

#include <experimental/random>
#include <iostream>

int main(int argc, char** argv)
{

    std::srand(std::time(nullptr));
    auto x = 0;
    std::vector<int> nums;

    while (nums.size() < 16) {
        x = std::experimental::randint(1, 16);
        if (std::find(nums.begin(), nums.end(), x) == nums.end()) {
            nums.push_back(x);
        }
    }

    auto p = std::unique_ptr<Puzzle>(new Puzzle(nums));
    p->run();
    return 0;
}
