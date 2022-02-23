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

            if ( garage1.head == nullptr) {
                garage1.head = tempStack.head;
            }
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

    /*
    string userInput;

    cout << "Where would you like to put" << newCar->name << endl;
    cout << "Garage 1: " << garage1.stackSize << endl;
    cout << "Garage 2: " << garage2.stackSize << endl;
    cout << "You can put your car in any garage that has less than 10 cars in it" << endl;

    while(userInput != "1" && userInput != "2") {
        cout << "Please enter 1 or 2 to enter either Garage ";
        cin >> userInput;
    }
*/
    if(garage1.stackSize == 10  && garage2.stackSize == 10) { cout << "GARAGE FULL. GO HOME"; return;}

     garage1.stackSize <= 10 ? garage1.Push(newCar) : garage2.Push(newCar);

}

void Garage::carWaiting() {

}

void Garage::checkCarPos() {

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
            departCar(inputStack->head);
            inputStack->Pop();
        }
    }
}
