//
// Created by bigbl on 2/22/2022.
//

#include "Garage.h"


/**
 *  Things I need to solve.
 *  1.) If a car departs and garage 1 or 2 is full then go to street stack.
 *  2.) Move blocking cars to the street
 *  3.) Move to two when 1 is full. Science.
 *
 *  @params (Car* newCar, Stack* Lane);
 */
void Garage::departCar(Stack &lane, bool isLane1) {

    Car *temp;
   /**
    * Lane 1 case
    *
    * 1.) If pushing in a lane, push cars to other lane, if lane is full then push to street,
    * 2.) Then push cars back into the same lane they were put out of.
    */

   int tempsize = 0;


   tempStack.reverse();
   temp = tempStack.head;

     if (isLane1) {
         if (temp == nullptr) {
             lane2.Push(temp);
         } else {
             while (temp->next != nullptr) {
                 if (lane2.stackSize < 10) {
                     lane2.Push(temp);
                     temp = temp->next;
                     tempStack.Pop();
                     tempsize++;
                 } else {
                     street.Push(temp);
                     temp = temp->next;
                     tempStack.Pop();
                 }
             }
         }

     } else {
         if (temp->next == nullptr) {
             lane1.Push(temp);
         } else {
             while (temp->next != nullptr) {
                 if (lane1.stackSize < 10) {
                     lane1.Push(temp);
                     temp = temp->next;
                     tempStack.Pop();
                     tempsize++;
                 } else {
                     street.Push(temp);
                     tempStack.Pop();
                     temp = temp->next;
                 }
             }
         }
     }

    tempStack.Pop();
    returnCar(tempsize, isLane1);

}

void Garage::arriveCar(Car* newCar) {

    if(lane1.stackSize == 10  && lane2.stackSize == 10) { cout << "GARAGE FULL. GO HOME"; return;}
     lane1.stackSize < 10 ? lane1.Push(newCar) : lane2.Push(newCar);

    printOutput();

}

/*
 * Don't repeat yourself
 * Make sure to include function depart Car in checkPos so
 * you can reduce logic repetition.
 */

bool Garage::checkCarPos(Car* newCar) {
    Car *temp;
    bool nameTrue = false;
    int popCount = 0;

    /**
     * BASE CASE FOR NAME NOT IN LIST
     */

    temp = lane1.head;
    while (temp != nullptr) {
        if (temp->name == newCar->name) {
            nameTrue = true;
        }
        temp = temp->next;
    }

    temp = lane2.head;
    while (temp != nullptr) {
        if (temp->name == newCar->name) {
            nameTrue = true;
        }
        temp = temp->next;
    }

    if(nameTrue == false) {
        return true;
    }

    /**
     * Case 1: New car is in lane1
     */

    temp = lane1.head;
    while (temp != nullptr) {
        if (temp->name == newCar->name) {
            lane1.PopMulti(popCount);
            tempStack.Push(temp);
            departCar(lane1, true);
            return true; // Call function that checks where car is located
        }
        tempStack.Push(temp);
        temp = temp->next;
        popCount++;
    }

    /**
    * Case 2: New car is in lane2
    */

    /*
    temp = tempStack.head;

    while(temp->next != nullptr) {
        tempStack.Pop();
        temp = temp->next;
    }
     */

    for(int i = 0; i < popCount; i++) {
        tempStack.Pop();
    }

    popCount = 0;


    temp = lane2.head;
    while (temp != nullptr) {
        if (temp->name == newCar->name) {
            lane2.PopMulti(popCount);
            tempStack.Push(temp);
            departCar(lane2, false);
            return true;
        }
        tempStack.Push(temp);
        temp = temp->next;
        popCount++;
    }

    return false;
}


    void Garage::printOutput() {
        usleep(1000000);
        system("cls");
        std::cout << R"(

   ______                                                 ___
  / ____/  ____ _   _____  ____ _   ____ _  ___          <  /
 / / __   / __ `/  / ___/ / __ `/  / __ `/ / _ \         / /
/ /_/ /  / /_/ /  / /    / /_/ /  / /_/ / /  __/        / /
\____/   \__,_/  /_/     \__,_/   \__, /  \___/        /_/
                                 /____/

)";
        lane1.displayAll();

        std::cout << R"(

   ______                                                 ___
  / ____/  ____ _   _____  ____ _   ____ _  ___          |__ \
 / / __   / __ `/  / ___/ / __ `/  / __ `/ / _ \         __/ /
/ /_/ /  / /_/ /  / /    / /_/ /  / /_/ / /  __/        / __/
\____/   \__,_/  /_/     \__,_/   \__, /  \___/        /____/
                                 /____/
)";

        lane2.displayAll();


    }


void Garage::decideAction(Stack * inputStack) {
    while(inputStack->head != nullptr) {
        if(inputStack->head->action == "A") {
            arriveCar( inputStack->head);
            inputStack->Pop();
        } else {
            checkCarPos(inputStack->head);
            inputStack->Pop();
        }
    }
}

void Garage::returnCar(int tempCars, bool isLane1) {
    if (isLane1) {
        lane1.Pop();
        for (int i = 0; i < tempCars; i++) {
            lane1.Push(lane2.head);
            lane2.Pop();
        }
        if (street.head == nullptr) {
            return;
        } else {
            while (street.head != nullptr) {
                lane1.Push(street.head);
                street.Pop();
            }
        }
    } else {
        lane2.Pop();
        for (int i = 0; i < tempCars; i++) {
            lane2.Push(lane1.head);
            lane1.Pop();
        }
        if (street.head == nullptr) {
            return;
        } else {
            while (street.head != nullptr) {
                lane2.Push(street.head);
                street.Pop();
            }
        }
    }
}
