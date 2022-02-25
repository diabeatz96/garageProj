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


/*
    std::cout << R"(

  ________  ___________  _______    _______   _______  ___________
 /"       )("     _   ")/"      \  /"     "| /"     "|("     _   ")
(:   \___/  )__/  \\__/|:        |(: ______)(: ______) )__/  \\__/
 \___  \       \\_ /   |_____/   ) \/    |   \/    |      \\_ /
  __/  \\      |.  |    //      /  // ___)_  // ___)_     |.  |
 /" \   :)     \:  |   |:  __   \ (:      "|(:      "|    \:  |
(_______/       \__|   |__|  \___) \_______) \_______)     \__|

)";
*/

string temp;
cin >> temp;

    return 0;
}
