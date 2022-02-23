#include <iostream>
#include "Stack.h"
#include "Garage.h"

int main() {

Garage newGarage;
Stack newstack;

newstack.loadFile();
newstack.reverse();

newstack.displayAll();

newGarage.decideAction(&newstack);

cout << endl << endl << "GARAGE 1" << endl;

newGarage.garage1.displayAll();

cout << endl << endl << "GARAGE 2" << endl;

newGarage.garage2.displayAll();

    return 0;
}
