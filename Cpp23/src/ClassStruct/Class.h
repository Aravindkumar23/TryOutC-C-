#pragma once

class Player {
    private:

       int x;
       int y;

    public:

        Player(); // Default constructor

        void move(int dx, int dy);

        Player(int xCoord, int yCoord);//   Parameterized constructor
        
        void display() const; // Method to display point coordinates

        ~Player(); // Destructor
};



