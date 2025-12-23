#include <iostream>
#include <string>

int main() {
    // Creating and initializing strings
    std::string str1 = "Hello, ";
    std::string str2 = "World!";    
    
    //concatenation
    std::string str3 = str1 + str2;
    std::cout << "Concatenated String: " << str3 << std::endl;

    // Finding length of a string
    std::cout << "Length of str3: " << str3.length() << std ::endl;
    // Accessing characters in a string
    std::cout << "First character of str3: " << str3[0] << std::endl;
    // Substring
    std::string substr = str3.substr(7, 5); // "World"
    std::cout << "Substring of str3: " << substr << std::endl;

    // Finding a substring
    size_t pos = str3.find("World");
    if (pos != std::string::npos) {
        std::cout << "'World' found at position: " << pos << std::endl;
    } else {
        std::cout << "'World' not found" << std::endl;
    }

    // Replacing a substring
    str3.replace(7, 5, "C++");
    std::cout << "After replacement: " << str3 << std::endl;

    // Converting to uppercase
    for (char &c : str3) {
        c = toupper(c);
    }
    std::cout << "Uppercase str3: " << str3 << std::endl;

    // Converting to lowercase
    for (char &c : str3) {          
        c = tolower(c);
    }
    std::cout << "Lowercase str3: " << str3 << std::endl;

    // Clearing a string
    str3.clear();
    std::cout << "Cleared str3, length now: " << str3.length() << std::endl;

    // Input string from user
    std::string userInput;
    std::cout << "Enter a string: ";
    std::getline(std::cin, userInput);
    std::cout << "You entered: " << userInput << std::endl;

    //whats the differenece between cin and getline
    std::string singleWord;
    std::cout << "Enter a single word: ";
    std::cin >> singleWord; // stops input at whitespace
    std::cout << "You entered (single word): " << singleWord << std::endl;
    
    // Demonstrating difference between cin and getline
    std::cin.ignore(); // to ignore the leftover newline character in the input buffer
    std::string fullLine;
    std::cout << "Enter a full line of text: ";
    std::getline(std::cin, fullLine); // reads the entire line including spaces
    std::cout << "You entered (full line): " << fullLine << std::endl;

    // String comparison 
        //compares length first if same then compares character by character
    std::string compareStr1 = "apple";
    std::string compareStr2 = "banana";
    if (compareStr1 == compareStr2) { // based on ascii values
        std::cout << compareStr1 << " is equal to " << compareStr2 << std::endl; //cases why they are equal, greater than, less than less than coz of comparison of ascii values
    } else if (compareStr1 < compareStr2) {
        std::cout << compareStr1 << " is less than " << compareStr2 << std::endl;
    } else {
        std::cout << compareStr1 << " is greater than " << compareStr2 << std::endl;
    }

    // String to number conversion
    std::string numStr = "12345";
    int num = std::stoi(numStr); //what is stoi //string to integer
    std::cout << "Converted number: " << num << std::endl;

    // Number to string conversion
    int anotherNum = 67890;
    std::string anotherNumStr = std::to_string(anotherNum);
    std::cout << "Converted string: " << anotherNumStr << std::endl;

    return 0;
}