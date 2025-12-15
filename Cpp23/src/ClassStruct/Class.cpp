
// common imports
#include <format>
#include <iostream>
#include <string>
// include header file
#include "Class.h"

Player::Player() : x(0), y(0) { // default constructor with initializer list
    std::cout << "Default Constructor called. Player initialized at (0,0)" << std::endl;
    Player::move(2,1);
} 
Player::Player(int x, int y) : x(x), y(y) { //perameterized constructor with initializer list
    std::cout << "parametrized Constructor called. Player initialized at (" << x << "," << y << ")" << std::endl;
    Player::move(2,1);
}

// Move the point by dx, dy
void Player::move(int dx, int dy) {
    x += dx;
    y += dy;
    std::cout << "Player moved to (" << x << "," << y << ")" << std::endl;
    std::cout << std::format("Using C++20 std::format: Player moved to ({}, {})", x, y) << std::endl;
}

void Player::display() const {
    std::cout << "Player is at (" << x << ", " << y << ")" << std::endl;
}

Player::~Player() {
    std::cout << "Destructor called. Player object is being destroyed." << std::endl;
}