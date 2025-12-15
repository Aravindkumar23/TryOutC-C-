#include <iostream>
#include "vector.h"

using namespace std;
vectorExample::vectorExample() {
    cout << "Vector constructor called." << endl;
    creationOfVector();
}

vectorExample::~vectorExample() {
    cout << "Vector destructor called." << endl;
}

void vectorExample::creationOfVector() {
    vector<int> vec;
    cout << "Vector of integers created." << endl;
    creationOfVectorDynamic(vec);
}

void vectorExample::creationOfVectorDynamic(vector<int>& vec) {
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    cout << "Added elements to vector: ";
    for (const int& val : vec) {
        cout << val << " ";
    }
    cout << endl;
}
