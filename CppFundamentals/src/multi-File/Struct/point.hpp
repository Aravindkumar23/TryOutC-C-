#pragma once

//structs are a way to group related data together
//they are similar to classes but have public members by default

struct Point {
        int x;
        int y;

        void print() const {
            std::cout << "Point(" << x << ", " << y << ")" << std::endl;
        }

        //similar to classes, structs can have member functions
};