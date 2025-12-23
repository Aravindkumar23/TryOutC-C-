#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Creating an unordered_map to store key-value pairs
    std::unordered_map<std::string, int> myUnorderedMap;
    // Inserting key-value pairs into the unordered_map
    myUnorderedMap["Apple"] = 1;
    myUnorderedMap["Banana"] = 2;
    myUnorderedMap["Orange"] = 3;   
    // Accessing and displaying unordered_map elements
    std::cout << "Unordered Map elements:" << std::endl;
    for(const auto& pair : myUnorderedMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    // Finding an element by key
    std::string searchKey = "Banana";
    auto it = myUnorderedMap.find(searchKey);
    if(it != myUnorderedMap.end()) {
        std::cout << "Found key " << searchKey << " with value: " << it->second << std::endl;
    } else {
        std::cout << "Key " << searchKey << " not found in the unordered_map." << std::endl;
    }
    // Removing an element by key
    myUnorderedMap.erase("Apple");
    std::cout << "Unordered Map elements after removing key 'Apple':" << std::endl;
    for(const auto& pair : myUnorderedMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // Demonstrating unordered_map properties: unordered keys
    myUnorderedMap["Grapes"] = 4;
    myUnorderedMap["Mango"] = 5;
    std::cout << "Unordered Map elements after adding 'Grapes' and 'Mango':" << std::endl;
    for(const auto& [key, value] : myUnorderedMap) {
        std::cout << "Key: " << key << ", Value: " << value << std::endl;
    }

    //unordered_map functions
    std::cout << "Unordered Map size: " << myUnorderedMap.size() << std::endl; //size of the unordered_map
    std::cout << "Is unordered_map empty? " << (myUnorderedMap.empty() ? "Yes" : "No") << std::endl;
        myUnorderedMap.clear(); //clears all elements
        //unordered_map add elements
    myUnorderedMap["Pineapple"] = 6;
    myUnorderedMap["Peach"] = 7;
    //insert with insert function
    myUnorderedMap.insert({"Kiwi", 8});
    //erase an element
    myUnorderedMap.erase("Pineapple");
    myUnorderedMap.at("Peach") = 77; //modifying value at
    myUnorderedMap.count("Kiwi"); //returns 1 if key "Kiwi" is present else 0
    std::unordered_map<std::string, int> anotherMap;
    anotherMap["Watermelon"] = 9;
    anotherMap["Papaya"] = 10;
    myUnorderedMap.swap(anotherMap); //swaps contents with another unordered_map
    
    return 0;
}