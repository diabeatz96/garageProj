//
// Created by bigbl on 2/22/2022.
//


#ifndef GARAGEPROJ_STACK_H
#define GARAGEPROJ_STACK_H

#include "string"
#include "iostream"
#include "fstream"

using namespace std;

class Stack {


public:
    struct Car {
        string name;
        int timesMoved{};
        Car *next = nullptr;
        Car *prev = nullptr;

        Car();

    };


    Car *head = nullptr;
    int stackSize = 10;

    /**
     * Functions for loading files into nodes.
     */

    void loadFile();
    void Prepend(Car* newCar);


};

#endif //GARAGEPROJ_STACK_H
