#include <iostream>
#include <memory>

int main() {
    std::cout << "Smart pointers example." << std::endl;
    
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(42);
    std::cout << "Unique Pointer Value: " << *uniquePtr << std::endl;
     // uniquePtr goes out of scope and is automatically deleted here

    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(100);
    std::shared_ptr<int> sharedPtr2 = sharedPtr1; // shared ownership
    std::cout << "Shared Pointer Value: " << *sharedPtr1 << ", Use Count: " << sharedPtr1.use_count() << std::endl;
    std::cout << "Shared Pointer Value: " << *sharedPtr2 << ", Get: " << sharedPtr2.get() << std::endl;

    std::shared_ptr<int> sharedPtr3 = std::make_shared<int>(200);
    sharedPtr2.swap(sharedPtr3);
    std::cout << "Shared Pointer swap pointer 2: " << *sharedPtr2 << std::endl;
    std::cout << "Shared Pointer swap pointer 3: " << *sharedPtr3 << std::endl;
     // sharedPtr1 and sharedPtr2 go out of scope and are automatically deleted here
    return 0;
}