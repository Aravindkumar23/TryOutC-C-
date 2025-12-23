#include <iostream>

int main() {
    int x;
    std::cout << "std::cout is used to print " << std::endl;
    std::cout << "std::cin to take input from user also >> is extract operation" << std::endl;
    std::cout << "Enter a number: ";
    std::cin >> x;
    std::cout << "You entered: " << x << std::endl;
    std::cerr << "std::cerr is used to print error messages" << std::endl;
    std::clog << "std::clog is used for logging information" << std::endl;
    std:: cout << "iostream methods also has w before it a new set of methods mentioning wide ex: wcin >> x : meaning wide character input" << std::endl;
    return 0;
}