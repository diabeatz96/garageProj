//
// Created by bigbl on 2/22/2022.
//

#ifndef GARAGEPROJ_GARAGE_H
#define GARAGEPROJ_GARAGE_H

#include "Stack.h"
#include "iostream"
#include "string"
#include "Car.h"
class Garage {

public:

    Stack garage1;
    Stack garage2;
    Stack street;
    Stack tempStack;


    void decideAction(Stack* inputStack);
    void departCar(Car* newCar);
    void arriveCar(Car* newCar);
    void carWaiting();
    bool checkCarPos(Car* newCar);
    void printOutput();

};


#endif //GARAGEPROJ_GARAGE_H
