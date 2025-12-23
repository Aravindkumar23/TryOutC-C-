#include <iostream>
#include "class.hpp"

int main() {
    int sum;
    Class obj1;
    obj1.setData(10, 20);
    sum = obj1.sumVal();
    std::cout << "Sum of data members: " << sum << std::endl;
    return 0;
}