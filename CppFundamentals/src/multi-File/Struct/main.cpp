#include <iostream>
#include "point.hpp"

int main() {
    
    Point p1;
    p1.x = 10;
    p1.y = 20;

    std::cout << "Point p1: (" << p1.x << ", " << p1.y << ")" << std::endl;

    Point p2 = {30, 40};
    p2.print();

    return 0;
}