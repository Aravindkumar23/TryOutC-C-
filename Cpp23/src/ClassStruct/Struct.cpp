#include <iostream>
#include "Struct.h"
#include "../Pointers/Pointers.h"

Point::Point() : x(0), y(0) { // default constructor with initializer list
    std::cout << "Default Constructor called. Point initialized at (0,0)" << std::endl;
    Point::move(2,1);
} 
Point::Point(int x, int y) : x(x), y(y) { //perameterized constructor with initializer list
    std::cout << "parametrized Constructor called. Point initialized at (" << x << "," << y << ")" << std::endl;
    Point::move(2,1);
}

// Move the point by dx, dy
void Point::move(int dx, int dy) {
    x += dx;
    y += dy;
    std::cout << "Point moved to (" << x << "," << y << ")" << std::endl;
}   

void Point::explictPointer(){
    Pointers ptr;
    Pointers* ptr2 = &ptr;
    std::cout << "Accessing testPointer via pointer: " << ptr2->testPointer << std::endl;
    ptr2->testPointer = 42;
    std::cout << "Updated testPointer via pointer: " << ptr2->testPointer << std::endl;
}