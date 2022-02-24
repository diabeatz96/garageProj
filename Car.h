//
// Created by Adam on 2/22/2022.
//

#ifndef GARAGEPROJ_CAR_H
#define GARAGEPROJ_CAR_H
#include "string"

using namespace std;

/**
 * Car should be a data type for data not a node class itself.
 *
 * Will update on V2 of Project.
 */

struct Car {
    string name;
    string action;
    int timesMoved{};
    Car *next = nullptr;
    Car() {
        timesMoved = 0;
        name = "";
    }

};

#endif //GARAGEPROJ_CAR_H
