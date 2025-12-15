//common imports 
#include <iostream>
#include <string>
#include <format>
// include header file
#include "Pointers.h"

Pointers::Pointers() : value(0) {
    std::cout << "Pointers class constructor called. Value initialized to 0." << std::endl;
}

Pointers::~Pointers() {
    std::cout << "Pointers class destructor called." << std::endl;
}