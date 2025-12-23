#include <iostream>
int main() {
    // For loop example
    for (int i = 0; i < 5; i++) {
        // Print the current value of i
        std::cout << "For Loop iteration: " << i << std::endl;
    }

    // While loop example
    int j = 0;
    while (j < 5) {
        // Print the current value of j
        std::cout << "While Loop iteration: " << j << std::endl;
        j++;
    }

    // Do-while loop example
    int k = 0;
    do {
        // Print the current value of k
        std::cout << "Do-While Loop iteration: " << k << std::endl;
        k++;
    } while (k < 5);

    int n[5] = {1,2,3,4,5};
     //range based for loop i.e for each loop
    for(int val : n) {
        std::cout << "Range-based For Loop value: " << val << std::endl;
    }

    return 0;
}