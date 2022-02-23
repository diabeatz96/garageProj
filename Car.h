//
// Created by Adam on 2/22/2022.
//

#ifndef GARAGEPROJ_CAR_H
#define GARAGEPROJ_CAR_H
#include "string"

using namespace std;

struct Car {
    string name;
    string garage;
    int timesMoved{};
    Car *next = nullptr;
    Car *prev = nullptr;
    Car() {
        timesMoved = 0;
        name = "";
    }

};

#endif //GARAGEPROJ_CAR_H
