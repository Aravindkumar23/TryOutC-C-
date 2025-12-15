#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void Day1ProblemDemo();
void simpleIntegerAddition();
void printSumOfDigits();
void reverseString();

void Day1ProblemDemo() {
    std::cout << "Demonstrating Day 1 problems in C++!" << std::endl;

    // Example: Simple arithmetic operation
   simpleIntegerAddition();

   // Example: Sum of digits of an integer
    printSumOfDigits();

    // Example: Reverse a string
    reverseString();

    // Example: String manipulation
    string greeting = "Hello";
    string name = "World";
    string message = greeting + ", " + name + "!";
    std::cout << message << std::endl;

    // Example: Looping through numbers
    std::cout << "Counting from 1 to 5:" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void simpleIntegerAddition() {
    int a = 5;
    int b = 10;
    int sum = a + b;
    std::cout << "The sum of " << a << " and " << b << " is " << sum << std::endl;
}

void printSumOfDigits() {
    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number;

    int sum = 0;
    while (number != 0) {
        sum += number % 10; // add the last digit to sum
        number /= 10;       // remove the last digit
    }

    std::cout << "The sum of the digits is: " << sum << std::endl;
}


//reverse the string representation.
void reverseString() {
    std::string str;
    std::cout << "Enter a string: ";
    std::cin >> str;

    std::string reversedStr(str.rbegin(), str.rend());
    // reverse using iterators this works because rbegin() returns a reverse iterator to the end of the string 
    //rend() returns a reverse iterator to the beginning of the string
    //rbegin() and rend() are used to create a new string that is the reverse of the original.
    std::cout << "Reversed string: " << reversedStr << std::endl;

    //other way to reverse a string
    char strC[100]; // buffer for up to 99 characters + '\0'

    cout << "Enter a string: ";
    cin.getline(strC, 100); // safer than cin >> str (handles spaces too)

    // Step 1: find length
    int length = 0;
    while (strC[length] != '\0') {
        length++;
    }

    // Step 2: reverse in place
    for (int i = 0; i < length / 2; i++) {
        char temp = strC[i];
        strC[i] = strC[length - i - 1];
        strC[length - i - 1] = temp;
    }

    cout << "Reversed string: " << strC << endl;

}