#pragma once

//Class variables without access specifier are private by default
//mentioning private explicitly for clarity
class Class {

    private:
    //private members
        int dataMember;
        int dataMember2;

        void addMethod(); //private method declaration

    public:

        Class();//Constructor declaration
    
        ~Class();//Destructor declaration
    
        int sumVal(); //class method declaration

        void setData(int value, int value2); //class method declaration

};