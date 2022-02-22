//
// Created by bigbl on 2/22/2022.
//

#include "Stack.h"


Stack::Car::Car() {
    timesMoved = 0;
    name = "";
}


void Stack::Prepend(Car* newCar) {
    Car* temp = new Car();
        head->next = temp;

    }

void Stack::loadFile() {
    ifstream inFile;
    string line;
    inFile.open("C:\\Users\\bigbl\\CLionProjects\\autoComplete\\assests\\scratch.txt"); //Absolute path for now cause im bad.

    /* Check if file is open, then we check if head is nullptr, if its not nullptr then do normal functionality */
    if(inFile.is_open()) {
        while (std::getline(inFile, line)) {
            Car* temp = new Car();
            if(head == nullptr) {
                head = temp;
                head->name = line;
                stackSize++;
            } else {
                Prepend(temp);
                stackSize++;
            }
        }
        inFile.close();
    } else {
        cout << "File input is not working!";
    }
}