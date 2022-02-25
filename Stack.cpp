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

    /* Check if file is open, then we check if head is nullptr, if its not nullptr then do normal functionality
     *
     *
     * **** Check first line then put into lane. No need to store into seperate stack. //IMPORVEMENT FOR V2
     * */

    if(inFile.is_open()) {
        while (inFile >> line) {
            Car* temp = new Car();
            if(head == nullptr) {
                head = temp;
                head->action = line;
                inFile >> line;
                head->name = line;
                stackSize++;
            } else {
                Prepend(temp);
                head->action = line;
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

string Stack::PopMulti(int amt) {
    Car* temp;


    if (head == nullptr) {
        return "NULL PTR";
    }

    if(amt == 0) {
        temp = head;
        head = head->next;
        stackSize--;
        return "ONE NODE ADDED";
    }
    for(int i = 0; i < amt; i++) {

        temp = head;
        head = head->next;
        stackSize--;
    }


    delete temp;
    return to_string(amt) + "Nodes Popped";
}


string Stack::Peek() {
    return isEmpty() ? "You don't have a head my friend" : "Your name is " + head->name + " and action is " + head->action;
}

bool Stack::isEmpty() {
    return (head == nullptr);
}

void Stack::displayAll() {
    Car * current = head;

    while (current != nullptr) {
        /*
        srand (time(NULL));
        int color = rand() % 14 + 1;
        textcolor(color);
        */

        /*
        std::cout << R"(

                 ______
                /|_||_\`.__
               (   _    _ _\
              =`-(_)--(_)-'

)";n*/

        cout << "NAME:" << current-> name << "\t";
        cout << "GARAGE: " << this->getName() << "\t";
        cout << "TIMES MOVED: " << current->timesMoved << "\t";
        cout << endl;
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

void Stack::textcolor(int color) {
        static int __BACKGROUND;

        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbiInfo;


        GetConsoleScreenBufferInfo(h, &csbiInfo);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                color + (__BACKGROUND << 4));
}

/** Simple Getter and Setter Methods */

const string &Stack::getName() const {
    return name;
}

void Stack::setName(const string &name) {
    Stack::name = name;
}

int Stack::getStackSize() const {
    return stackSize;
}

void Stack::setStackSize(int stackSize) {
    Stack::stackSize = stackSize;
}


