#include <iostream>
#include <set>

int main() {

    //scenarios where sets can be used are when we need to store unique elements in a sorted order

    //std::set initialization and basic operations

    std::set<int> initializedSet = {5, 10, 15, 20};
    std::cout << "Initialized set elements:" << std::endl;
    for(const int& element : initializedSet) {
        std::cout << element << std::endl;
    }

    // Create a set of integers
    std::set<int> mySet;
    // Inserting elements into the set
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(20); // Duplicate element, will not be added
    // Displaying the elements of the set
    std::cout << "Elements in the set:" << std::endl;
    for(const int& element : mySet) {
        std::cout << element << std::endl;
    }
    // Checking if an element exists in the set
    int searchElement = 20;
    if(mySet.find(searchElement) != mySet.end()) {
        std::cout << searchElement << " found in the set." << std::endl;
    } else {
        std::cout << searchElement << " not found in the set." << std::endl;
    }
    // Removing an element from the set
    mySet.erase(10);
    std::cout << "Elements in the set after removing 10:" << std::endl;
    for(const int& element : mySet) {
        std::cout << element << std::endl; 
    }

    // Demonstrating set properties: uniqueness and ordering
    mySet.insert(15);
    mySet.insert(5);
    std::cout << "Elements in the set after adding 15 and 5:" << std::endl;

    for(const int& element : mySet) {
        std::cout << element << std::endl; 
    }

    //begin and end functions
    std::cout << "Using begin() and end() to iterate through the set:" << std::endl;
    for(auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << std::endl;
    }

      //begin represents the first element in the set
      //end represents one past the last element in the set which is why we use != in the loop condition'

    std::cout << *mySet.end() << std::endl; //prints garbage value as end() points to one past the last element

    //rbegin and rend functions
    std::cout << "Using rbegin() and rend() to iterate through the set in reverse order:" << std::endl;
    for(auto it = mySet.rbegin(); it != mySet.rend(); ++it) {
        std::cout << *it << std::endl;
    }

     //rbegin represents the last element in the set
     //rend represents one before the first element in the set which is why we use != in the loop condition
     //this does backward traversal of the set

    //cbegin and cend functions 
        //const versions of begin and end can't modify the elements
    std::cout << "Using cbegin() and cend() to iterate through the set:" << std::endl;
    for(auto it = mySet.cbegin(); it != mySet.cend(); ++it) {
        std::cout << *it << std::endl;
    }

    //crbegin and crend functions
        //const versions of rbegin and rend can't modify the elements
    std::cout << "Using crbegin() and crend() to iterate through the set in reverse order:" << std::endl;
    for(auto it = mySet.crbegin(); it != mySet.crend(); ++it) {
        std::cout << *it << std::endl;
    }

    //size function
    std::cout << "Size of the set: " << mySet.size() << std::endl;

    //clear function
    mySet.clear();
    std::cout << "Size of the set after clear(): " << mySet.size() << std::endl;

    return 0;
}