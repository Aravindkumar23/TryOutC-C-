#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<int, std::string> myMap;
    // Inserting key-value pairs into the map
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";
    // Accessing and displaying map elements
    std::cout << "Map elements:" << std::endl;
    for(const auto& pair : myMap) {
        std::cout << "pair : " << &pair << std::endl;
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    // Finding an element by key
    int searchKey = 2;
    auto it = myMap.find(searchKey);
    if(it != myMap.end()) {
        std::cout << "Found key " << searchKey << " with value: " << it->second << std::endl;
    } else {
        std::cout << "Key " << searchKey << " not found in the map." << std::endl;
    }
    // Removing an element by key
    myMap.erase(1);
    std::cout << "Map elements after removing key 1:" << std::endl;
    for(const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // Demonstrating map properties: ordered keys
    myMap[4] = "Four";
    myMap[0] = "Zero";
    std::cout << "Map elements after adding keys 4 and 0:" << std::endl;
    for(const auto& [key, value] : myMap) {
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
    }

    //map functions 
    std::cout << "Map size: " << myMap.size() << std::endl; //size of the map
    std::cout << "Is map empty? " << (myMap.empty() ? "Yes" : "No") << std::endl;
        myMap.clear(); //clears all elements

     //map add elements
    myMap[5] = "Five";
    myMap[6] = "Six";   
    
    //push with insert function
    myMap.insert({7, "Seven"});

    //erase an element
    myMap.erase(5);
    
    
    myMap.at(6) = "SIX"; //modifying value at key 6
    myMap.count(7); //returns 1 if key 7 is present else 0

    myMap.swap(myMap); //swaps contents with another map

    myMap.emplace(8, "Eight"); //inserts a new key-value pair
    myMap.emplace_hint(myMap.begin(), 9, "Nine"); //inserts with hint

    myMap.lower_bound(6); //returns iterator to first element not less than key 6
    myMap.upper_bound(7); //returns iterator to first element greater than key 7
    myMap.equal_range(6); //returns pair of iterators for range of key 6

    
    return 0;
}