#include <iostream>

void demonstratePointer(int* ptr){
    *ptr = 10; //pointers can be null, so we should always check before dereferencing
}

void demonstrateReference(int& ref){
    ref = 20; //reference cannot be null and must be initialized
}

void demonstrateNonReference(int val){
    val = 30; 
    std::cout << "Inside demonstrateNonReference, val: " << val << std::endl;
}

int main() {
    int var = 42;
    int *ptr = &var; // Pointer initialized to the address of var

    std::cout << "Value of var: " << var << std::endl;
    std::cout << "Address of var: " << &var << std::endl;
    std::cout << "Value of ptr (address of var): " << ptr << std::endl;
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl;

    // Modifying the value of var using the pointer
    *ptr = 100;
    std::cout << "After modifying value through ptr:" << std::endl;
    std::cout << "Value of var: " << var << std::endl;
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl;

    //why pointer is different from reference   
    int anotherVar = 200;
    ptr = &anotherVar; // Pointer now points to anotherVar
    std::cout << "After changing ptr to point to anotherVar:" << std::endl;
    std::cout << "Value of anotherVar: " << anotherVar << std::endl;
    std::cout << "Value of ptr (address of anotherVar): " << ptr << std::endl;
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl;

    //why pointer is suggested to be used carefully and directly modifying memory can be dangerous
    int *nullPtr = nullptr; 
    // Pointer initialized to null
    // Uncommenting the following line would lead to undefined behavior
    // std::cout << "Value pointed to by nullPtr: " << *nullPtr << std::endl;

    //the reason why pointer is used insted of modifying memory directly is to avoid undefined behavior and potential crashes.
    demonstratePointer(&var);
    std::cout << "After demonstratePointer function call:" << std::endl;
    std::cout << "Value of var: " << var << std::endl;

    demonstrateReference(var);
    std::cout << "After demonstrateReference function call:" << std::endl;
    std::cout << "Value of var: " << var << std::endl;

    demonstrateNonReference(var);
    std::cout << "After demonstrateNonReference function call:" << std::endl;
    std::cout << "Value of var: " << var << std::endl;

    return 0;
}