#include <iostream>
#include <version>   // optional: confirms C++23 features are visible

using namespace std;
// using namespace methods; // hypothetical namespace for C++23 features

void createModuler();
void InputCatcher();
void initiateConfusions();
void stdFunctionality();
std::string input;
int main() {
    std::cout << "🚀 Hello from C++!" << std::endl;
    std::cout << "C++ version: " << __cplusplus << std::endl;

#if __cplusplus >= 202302L
    std::cout << "Using C++23 standard ✅" << std::endl;
#else
    std::cout << "Not compiled as C++23 ❌" << std::endl;
#endif
    createModuler();
}

void createModuler() {
        // Example function to demonstrate C++23 modules (if supported)
        std::cout << "Creating a module in C++23!" << std::endl;
        std::cout << "Where do you think these methods are linked?" << std::endl;
        InputCatcher();
}

void InputCatcher() {
    std::getline(std::cin, input);
    std::cout << "the input :  " << input << " is also called using a different method" << std::endl;
    initiateConfusions();
}

void initiateConfusions() {
    std::cout << "This function is to create confusion about where methods are linked from." << std::endl;
    std::cout << "Is it from modules, namespaces, or elsewhere?" << std::endl;
    std::cout << "Let's find out what is std mean why it is used!" << std::endl;
    stdFunctionality();
}

void stdFunctionality() {
    std::cout << "The 'std' namespace is the standard namespace in C++." << std::endl;
    std::cout << "It contains all the standard functions, classes, and objects provided by the C++ Standard Library." << std::endl;
    std::cout << "Using 'std::' allows you to access these standard components without naming conflicts." << std::endl;
    std::cout << "For example, 'std::cout' is used for outputting to the console." << std::endl;
    cout << "even without std:: C++ default function works but why it is necessary?" << endl;
    std::cout << "The reason is to avoid naming conflicts with other libraries or user-defined functions." << std::endl;
    std::cout << "By specifying 'std::', you make it clear that you are referring to the standard library version." << std::endl;
    std::cout << "can user defined lib can be declared same as std::?" << std::endl;
    std::cout << "Yes, users can define their own namespaces to avoid conflicts with the standard namespace." << std::endl;
    std::cout << "For example, you could create a namespace called 'myLib' and define your own functions and classes within it." << std::endl;
    std::cout << "This way, you can have functions with the same name as those in 'std' without any conflicts." << std::endl;
    cout << "not to name std that way we can call default functions?" << endl;
    cout << "Without using the 'std::' prefix or a 'using namespace std;' directive, you would need to define your own functions or classes with the same names as those in the standard library." << endl;
}



