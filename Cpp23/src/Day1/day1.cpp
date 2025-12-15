
#include <string>
#include <iostream>
using namespace std;

//declarations
string y;
void Day1Function();
void PrimitiveTypes();
void SignedUnsignedTypes();
void ReferenceTypes();
void Error();


//in this file blockscoped variable is been used to demonstrate primitive types, signed unsigned types and reference types in C++.

void Day1Function() {
    std::cout << "This is Day 1 function from day1.cpp!" << std::endl;
    std::cout << "Learning what primitive type is in C++." << std::endl;
    PrimitiveTypes();
    std::cout << "now looking out for what is signed and unsigned in C++." << std::endl;
    SignedUnsignedTypes();
    std::cout << "now looking out for what is reference type in C++." << std::endl;
    ReferenceTypes();
    std::cout << "you can tryout error scenarios in this error function" << std::endl;
    Error();
}

void PrimitiveTypes() {
    int integerVar = 42;               // Integer type
    double doubleVar = 3.14;           // Floating-point type
    char charVar = 'A';                // Character type
    bool boolVar = true;               // Boolean type
    short shortVar = 10;               // Short integer type
    long longVar = 100000L;           // Long integer type
    float floatVar = 2.71f;           // Single-precision floating-point type
    string stringVar = "Hello, C++!"; // String type
    y = "Global variable y";          // global variable
    std::cout << "Integer: " << integerVar << std::endl;
    std::cout << "Double: " << doubleVar << std::endl;
    std::cout << "Character: " << charVar << std::endl;
    std::cout << "Boolean: " << std::boolalpha << boolVar << std::endl;
    std::cout << "Short: " << shortVar << std::endl;
    std::cout << "Long: " << longVar << std::endl;
    std::cout << "Float: " << floatVar << std::endl;
    std::cout << "String: " << stringVar << std::endl; // string is not a primitive type
}

void SignedUnsignedTypes() {
    signed int signedVar = -42;        // Signed integer type - can be negative
    unsigned int unsignedVar = 42;     // Unsigned integer type - cannot be negative
    std::cout << "Signed Integer: " << signedVar << std::endl;
    std::cout << "Unsigned Integer: " << unsignedVar << std::endl;
    // Dangerous case:
    unsigned int underflow = 0 - 1;  // wraps around!
    cout << "underflow = " << underflow << endl;  // large number max value of unsigned int since it cant be negative it loops on to max value.
}

void ReferenceTypes() {
    int original = 10;
    int& ref = original; // ref is a reference to original
    ref += 5;           // modifies original through ref
    std::cout << "Original after modifying ref: " << original << std::endl; // Outputs 15
}



void Day1Assessment() {
    std::cout << "This is Day 1 Assessment function from day1.cpp!" << std::endl;
    std::cout << " read integer." << std::endl;
    PrimitiveTypes();
    std::cout << "print sum of digits" << std::endl;
    SignedUnsignedTypes();
    std::cout << "reverse the string representation" << std::endl;
    ReferenceTypes();
}


void Error(){
    std::cout << "This is Error function from day1.cpp!" << std::endl;
    std::cout << "accessing another block scoped variable inside here " << std::endl;
    // std::cout << "Trying to access x: " << x << std::endl;  // This will cause an error because x is not in scope here
     std::cout << "Trying to access y: " << y << std::endl;  // y is global, so this is fine
}