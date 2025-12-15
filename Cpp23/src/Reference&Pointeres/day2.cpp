#include <iostream>
#include <string>


void Day2Topics();
void PointerExample();
void ReferenceExample();

void Day2Topics(){
    std::cout <<"Learning Pointers and References" << std::endl;
    std::cout << "Pointers:" << std::endl;
    PointerExample();
    std::cout << "References:" << std::endl;
    ReferenceExample();
}

void PointerExample(){
    int var = 42;
    int* ptr = &var; // Pointer to var

    std::cout << "Value of var: " << var << std::endl;
    std::cout << "Address of var: " << &var << std::endl;
    std::cout << "Pointer ptr points to address: " << ptr << std::endl;
    std::cout << "Value at address ptr points to: " << *ptr << std::endl;

    // Modifying value using pointer
    *ptr = 100;
    std::cout << "New value of var after modifying through pointer: " << var << std::endl;
}

void ReferenceExample(){
    int var = 50;
    int& ref = var; // Reference to var

    std::cout << "Value of var: " << var << std::endl;
    std::cout << "Reference ref refers to value: " << ref << std::endl;

    // Modifying value using reference
    ref = 200;
    std::cout << "New value of var after modifying through reference: " << var << std::endl;
}