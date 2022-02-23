//
// Created by bigbl on 2/22/2022.
//

#include "Stack.h"



void Stack::Prepend(Car* newCar) {
        newCar->next = head;
        head = newCar;
    }

void Stack::loadFile() {
    ifstream inFile;
    string line;
    inFile.open("cars.txt"); //Absolute path for now cause im bad.

    /* Check if file is open, then we check if head is nullptr, if its not nullptr then do normal functionality */
    if(inFile.is_open()) {
        while (inFile >> line) {
            Car* temp = new Car();
            if(head == nullptr) {
                head = temp;
                head->garage = line;
                inFile >> line;
                head->name = line;
                stackSize++;
            } else {
                Prepend(temp);
                head->garage = line;
                inFile >> line;
                head->name = line;
                stackSize++;
            }
        }
        inFile.close();
    } else {
        cout << "File input is not working!";
    }
}

string Stack::Pop() {
    Car* temp;

    if (head == nullptr) {
        return "NULL PTR";
    }

    temp = head;
    head = head->next;
    stackSize--;
    delete temp;
    return "Node Popped";
}

string Stack::Peek() {
    return isEmpty() ? "You don't have a head my friend" : "Your name is " + head->name + " and garage is " + head->garage;
}

bool Stack::isEmpty() {
    return (head == nullptr);
}

void Stack::displayAll() {
    Car * current = head;

    while (current != nullptr) {
        cout << "NAME:" << current-> name << endl;
        cout << "GARAGE: " << current->garage << endl;
        current = current->next;
    }
}

void Stack::Push(Car *newCar) {
    Car *temp = new Car(*(newCar));

    if(head == nullptr) {
        head = temp;
        head->next = nullptr;
        head->timesMoved+=1 ;
        stackSize++;
    } else {
        temp->next = head;
        head = temp;
        temp->timesMoved += 1;
        stackSize++;
    }
}

void Stack::reverse() {

    if(head == nullptr || head->next == nullptr) {
        return;
    }

    Car* previous = nullptr;
    Car* current = head;
    Car* after = head;

    while(current != nullptr) {
        after = after->next;
        current->next = previous;
        previous = current;
        current = after;
    }


    head = previous;
}

