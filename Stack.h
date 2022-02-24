//
// Created by bigbl on 2/22/2022.
//


#ifndef GARAGEPROJ_STACK_H
#define GARAGEPROJ_STACK_H

#include "string"
#include "iostream"
#include "fstream"
#include "Car.h"
#include <Windows.h>
#include <unistd.h>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <utility>


using namespace std;

class Stack {



public:


    Car *head = nullptr;
    Car *tail = nullptr;
    string name = "";

    const string &getName() const;

    void setName(const string &name);

    int getStackSize() const;

    void setStackSize(int stackSize);

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
    void textcolor(int color);
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
