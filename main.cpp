#include <iostream>
#include "Stack.h"
#include "Garage.h"


int main() {

Garage newGarage;
Stack newstack;

newGarage.lane1.setName("Garage 1");
newGarage.lane2.setName("Garage 2");

newstack.loadFile();
newstack.reverse();

newGarage.decideAction(&newstack);


return 0;

}
