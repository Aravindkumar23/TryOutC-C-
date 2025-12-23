#include <iostream>
#include "class.hpp"

Class::Class() {
    std::cout << "class constructor called." << std::endl;
}

Class::~Class() {
    std::cout << "class destructor called." << std::endl;
}

int Class::sumVal() {
    std::cout << "Data member: " << dataMember << std::endl;
    return dataMember + dataMember2;
}

void Class::setData(int value, int value2) {
    dataMember = value;
    dataMember2 = value2;
}