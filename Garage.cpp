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
void Garage::departCar(Car* newCar, Stack& lane, bool isLane1) {

    Car *temp;
   /**
    * Lane 1 case
    */

   temp = tempStack.head;

    if(isLane1) {
        lane1.Pop();
        while (temp->next != nullptr) {
            lane2.Push(temp);
            temp = temp->next;
        }
    } else {
        lane2.Pop();
        while (temp->next != nullptr) {
            lane1.Push(temp);
            temp = temp->next;
        }
    }

    /**
     *  Base-Case Check to see if in array, if not we just return, no popping no nothing.
     */

}

void Garage::arriveCar(Car* newCar) {

    if(lane1.stackSize == 10  && lane2.stackSize == 10) { cout << "GARAGE FULL. GO HOME"; return;}
     lane1.stackSize <= 10 ? lane1.Push(newCar) : lane2.Push(newCar);

}

/*
 * Don't repeat yourself
 * Make sure to include function depart Car in checkPos so
 * you can reduce logic repetition.
 */

bool Garage::checkCarPos(Car* newCar) {
    Car *temp;

    Stack Lane1Copy = lane1;
    Stack Lane2Copy = lane2;

    /**
     * Case 1: New car is in lane1
     */

    temp = lane1.head;
    while (temp != nullptr) {
        if (temp->name == newCar->name) {
            departCar(newCar, lane1, true);
            return true; // Call function that checks where car is located
        }
        tempStack.Push(temp);
        temp = temp->next;
        lane1.Pop();
    }

    /**
    * Case 2: New car is in lane2
    */

    temp = lane2.head;
    while (temp != nullptr) {
        if (temp->name == newCar->name) {
            departCar(newCar, lane2, false);
            return true;
        }
        tempStack.Push(temp);
        temp = temp->next;
        lane2.Pop();
    }

    /**
   * Case 3: Neither is the case
   */

    lane1 = Lane1Copy;
    lane2 = Lane2Copy;

    tempStack.stackSize = 0;

    return false;
}


    void Garage::printOutput() {

    }


void Garage::decideAction(Stack * inputStack) {
    while(inputStack->head != nullptr) {
        if(inputStack->head->garage == "A") {
            arriveCar( inputStack->head);
            inputStack->Pop();
        } else {
            checkCarPos(inputStack->head);
            inputStack->Pop();
        }
    }
}
