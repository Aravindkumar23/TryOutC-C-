#include <iostream>

void demonstrateReference(int &ref) {
    ref += 10; // Modifying the original variable through the reference
}

int main() {

    //reference is a name to same variable namespace
    //once assigned cannot be changed to reference another variable

    
    int a = 10;
    int &refA = a; // refA is a reference to a

    std::cout << "Initial value of a: " << a << std::endl;
    std::cout << "Value of refA (reference to a): " << refA << std::endl;

    // Modifying the value using the reference
    refA = 20;
    std::cout << "After modifying refA:" << std::endl;
    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Value of refA: " << refA << std::endl;

    // Demonstrating that references cannot be null or reassigned
    int b = 30;
    refA = b; 
    
    /* error is not thrown, once reference is assigned it cannot be references cannot be reassigned,
    but the values inside it can be changed by const values */

    std::cout << "After attempting to reassign refA to b:" << std::endl;
    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Value of refA: " << refA << std::endl;

    std::cout << "Before calling demonstrateReference, b: " << b << std::endl;
    demonstrateReference(b);
    std::cout << "Value of b: " << b << std::endl;

    return 0;
}

