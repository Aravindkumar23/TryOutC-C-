#pragma once

struct Point {
    int x;
    int y;

    Point(); // Default constructor

    void move(int dx, int dy);

    Point(int xCoord, int yCoord);//   Parameterized constructor

    void display() const; // Method to display point coordinates
    void explictPointer();
};