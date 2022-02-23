#include <iostream>
#include "Stack.h"
#include "Garage.h"


int main() {

Garage newGarage;
Stack newstack;

newstack.loadFile();
newstack.reverse();


    std::cout << R"(

   ______                                                 ___
  / ____/  ____ _   _____  ____ _   ____ _  ___          <  /
 / / __   / __ `/  / ___/ / __ `/  / __ `/ / _ \         / /
/ /_/ /  / /_/ /  / /    / /_/ /  / /_/ / /  __/        / /
\____/   \__,_/  /_/     \__,_/   \__, /  \___/        /_/
                                 /____/

)";

    newGarage.decideAction(&newstack);
    newGarage.garage1.displayAll();


    std::cout << R"(

   ______                                                 ___
  / ____/  ____ _   _____  ____ _   ____ _  ___          |__ \
 / / __   / __ `/  / ___/ / __ `/  / __ `/ / _ \         __/ /
/ /_/ /  / /_/ /  / /    / /_/ /  / /_/ / /  __/        / __/
\____/   \__,_/  /_/     \__,_/   \__, /  \___/        /____/
                                 /____/
)";

newGarage.garage2.displayAll();

string temp;
cin >> temp;

    return 0;
}
