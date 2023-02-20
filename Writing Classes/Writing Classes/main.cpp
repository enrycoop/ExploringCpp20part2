#include <iostream>

struct point
{
    double x;
    double y;
};

int main(int argc, const char * argv[]) {
    point origin{}, unity{};
    origin.x = 0;
    origin.y = 0;
    unity.x = 1;
    unity.y = 1;
    
    std::cout << "origin = (" << origin.x << ", " << origin.y << ")\n";
    std::cout << "unity  = (" << unity.x  << ", " << unity.y  << ")\n";
    return 0;
}
