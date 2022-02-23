//
// Created by bigbl on 2/22/2022.
//

#include "Garage.h"

void Garage::departCar(Car* newCar) {
    Car *temp;
    bool isGarage1 = true;
    bool isGarage2 = true;

    /**
     *  Base-Case Check to see if in array, if not we just return, no popping no nothing.
     */

        temp = garage1.head;

        while(temp != nullptr) {
            if(temp->name == newCar->name) {
                isGarage2= false;
                garage1.Pop();
                break;
            }

            tempStack.Push(temp);
            temp = temp->next;
            garage1.Pop();
        }


        if (garage2.head != nullptr && garage1.stackSize >= 9) {
            temp = garage2.head;
            while (temp != nullptr) {
                if (temp->name == newCar->name) {
                    isGarage1 = false;
                    garage2.Pop();
                    break;
                }
                tempStack.Push(temp);
                temp = temp->next;
                garage2.Pop();
            }
        }

        if(isGarage1 && !isGarage2) {
            while(tempStack.head != nullptr) {
                garage1.Push(tempStack.head);
                tempStack.Pop();
            }
        }

        if(isGarage2 && !isGarage1) {
            while(tempStack.head != nullptr) {
                garage1.Push(tempStack.head);
                tempStack.Pop();
            }
    }
        tempStack.stackSize = 0;
}

void Garage::arriveCar(Car* newCar) {

    if(garage1.stackSize == 10  && garage2.stackSize == 10) { cout << "GARAGE FULL. GO HOME"; return;}
     garage1.stackSize <= 10 ? garage1.Push(newCar) : garage2.Push(newCar);

}


bool Garage::checkCarPos(Car* newCar) {
    Car *temp;

    temp = garage1.head;
    while (temp != nullptr) {
        if (temp->name == newCar->name) {
            return true;
        }
        temp = temp->next;
    }

    temp = garage2.head;
    while (temp != nullptr) {
        if (temp->name == newCar->name) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

    void Garage::printOutput() {

    }


void Garage::decideAction(Stack * inputStack) {
    while(inputStack->head != nullptr) {
        if(inputStack->head->garage == "A") {
            inputStack->head->timesMoved += 1;
            arriveCar( inputStack->head);
            inputStack->Pop();
        } else {
            inputStack->head->timesMoved += 1;
            if(checkCarPos(inputStack->head)) {
                departCar(inputStack->head);
            }
            inputStack->Pop();
        }
    }
}
