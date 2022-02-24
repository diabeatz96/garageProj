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


    std::cout << R"(

   ______                                                 ___
  / ____/  ____ _   _____  ____ _   ____ _  ___          <  /
 / / __   / __ `/  / ___/ / __ `/  / __ `/ / _ \         / /
/ /_/ /  / /_/ /  / /    / /_/ /  / /_/ / /  __/        / /
\____/   \__,_/  /_/     \__,_/   \__, /  \___/        /_/
                                 /____/

)";

    newGarage.decideAction(&newstack);
    newGarage.lane1.displayAll();


    std::cout << R"(

   ______                                                 ___
  / ____/  ____ _   _____  ____ _   ____ _  ___          |__ \
 / / __   / __ `/  / ___/ / __ `/  / __ `/ / _ \         __/ /
/ /_/ /  / /_/ /  / /    / /_/ /  / /_/ / /  __/        / __/
\____/   \__,_/  /_/     \__,_/   \__, /  \___/        /____/
                                 /____/
)";

newGarage.lane2.displayAll();

    std::cout << R"(

  ________  ___________  _______    _______   _______  ___________
 /"       )("     _   ")/"      \  /"     "| /"     "|("     _   ")
(:   \___/  )__/  \\__/|:        |(: ______)(: ______) )__/  \\__/
 \___  \       \\_ /   |_____/   ) \/    |   \/    |      \\_ /
  __/  \\      |.  |    //      /  // ___)_  // ___)_     |.  |
 /" \   :)     \:  |   |:  __   \ (:      "|(:      "|    \:  |
(_______/       \__|   |__|  \___) \_______) \_______)     \__|

)";

    newGarage.street.displayAll();

string temp;
cin >> temp;

    return 0;
}
