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

    Stack lane1;
    Stack lane2;
    Stack street;
    Stack tempStack;


    void decideAction(Stack* inputStack);
    void departCar(Car* newCar, Stack& lane1, bool isLane1);
    void arriveCar(Car* newCar);
    bool checkCarPos(Car* newCar);
    void printOutput();

};


#endif //GARAGEPROJ_GARAGE_H
