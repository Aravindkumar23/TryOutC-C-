#include <iostream>
#include <array>

void rawArray() {
    // Declare and initialize an array of integers
    int numbers[5] = {10, 20, 30, 40, 50};

    // Accessing array elements using index
    std::cout << "Array elements using index:" << std::endl;
    for(int i = 0; i < 5; ++i) {
        std::cout << "Element at index " << i << ": " << numbers[i] << std::endl;
    }

    // Modifying array elements
    numbers[2] = 100; // Change the third element (index 2) to 100
    std::cout << "\nAfter modifying the third element:" << std::endl;
    for(int i = 0; i < 5; ++i) {
        std::cout << "Element at index " << i << ": " << numbers[i] << std::endl;
    }

    // Using a pointer to traverse the array
    std::cout << "\nArray elements using pointer arithmetic:" << std::endl;
    int* ptr = numbers; // Pointer to the first element of the array
    for(int i = 0; i < 5; ++i) {
        std::cout << "Element at index " << i << ": " << *(ptr + i) << std::endl;
    }

}

void stdArray() {
    // Declare and initialize a std::array of integers
    std::array<int, 5> numbers = {10, 20, 30, 40, 50};

    // Accessing array elements using at() method

     //  size_t is the appropriate type for array indices
    std::cout << "Array elements using at() method:" << std::endl;
    for(size_t i = 0; i < numbers.size(); ++i) { //why pre increment is preferred ? it avoids creating a temporary copy
        std::cout << "Element at index " << i << ": " << numbers.at(i) << std::endl;
    }

    // Modifying array elements
    numbers.at(2) = 100; // Change the third element (index 2) to 100
    std::cout << "\nAfter modifying the third element:" << std::endl;
    for(size_t i = 0; i < numbers.size(); ++i) {
        std::cout << "Element at index " << i << ": " << numbers.at(i) << std::endl;
    }

    // Using range-based for loop to traverse the array
    std::cout << "\nArray elements using range-based for loop:" << std::endl;
    for(const auto& num : numbers) {
        std::cout << num << std::endl;
    }
}

int main() {
    
    //raw arrays how it works
    rawArray();

    std::cout << "-----------------------------------" << std::endl;
    
    //std::array how it works
    stdArray();

    return 0;
}