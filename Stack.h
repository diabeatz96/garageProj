//
// Created by bigbl on 2/22/2022.
//


#ifndef GARAGEPROJ_STACK_H
#define GARAGEPROJ_STACK_H

#include "string"
#include "iostream"
#include "fstream"
#include "Car.h"


using namespace std;

class Stack {



public:


    Car *head = nullptr;
    Car *tail = nullptr;

    int stackSize = 0;

    /**
     * Functions for loading files into nodes.
     */

    void loadFile();


    /**
     * Stack functions, Push, pop, peek, isempty, reverse
     */

    void Prepend(Car* newCar);
    void Push(Car* newCar);
    string Pop();
    string Peek();
    bool isEmpty();
    void reverse();
    /**
     * Display Functions
     */

    void displayAll();

};

#endif //GARAGEPROJ_STACK_H
