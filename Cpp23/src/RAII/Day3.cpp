#include <iostream>
#include <vector>


void Day3Topics();
void badRAII();

void Day3Topics() {
    std::cout << "This is Day 3 function from Day3.cpp!" << std::endl;
}


void badRAII() {
    int* data = new int[100]; //this represents array of 100 integers and its pointer is stored in data
    // Oops, forgot to delete data!
}

// Note: The above function demonstrates bad RAII practice by allocating
// memory without proper deallocation. In real code, prefer using smart
// pointers or containers like std::vector to manage resources automatically.

void goodRAII() {
    std::vector<int> data(100);
    // Memory is automatically managed and will be freed when 'data' goes out of scope.
}