#include <iostream>
#include <unordered_set>

int main() {
    //similar behavior as set but unordered_set does not maintain any order of elements
    //set is O(log n) for insertions, deletions, and lookups
    //unordered_set is average O(1) for insertions, deletions, and lookups

    // Scenarios where unordered_set can be used:
    // 1. When we need to store unique elements without any specific order.
    // 2. When we require average O(1) time complexity for insertions, deletions, and lookups.

    // Creating an unordered_set of integers
    std::unordered_set<int> myUnorderedSet;

    // Inserting elements into the unordered_set
    myUnorderedSet.insert(10);
    myUnorderedSet.insert(20);
    myUnorderedSet.insert(30);
    myUnorderedSet.insert(20); // Duplicate element, will not be added

    // Displaying the elements of the unordered_set
    std::cout << "Elements in the unordered_set:" << std::endl;
    for(const int& element : myUnorderedSet) {
        std::cout << element << std::endl;
    }

    // Checking if an element exists in the unordered_set
    int searchElement = 20;
    if(myUnorderedSet.find(searchElement) != myUnorderedSet.end()) {
        std::cout << searchElement << " found in the unordered_set." << std::endl;
    } else {
        std::cout << searchElement << " not found in the unordered_set." << std::endl;
    }

    // Removing an element from the unordered_set
    myUnorderedSet.erase(10);
    std::cout << "Elements in the unordered_set after removing 10:" << std::endl;
    for(const int& element : myUnorderedSet) {
        std::cout << element << std::endl; 
    }

    return 0;
}