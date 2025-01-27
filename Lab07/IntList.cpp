#include "IntList.h"
#include <iostream>

using namespace std;

IntList::IntList() : head(nullptr), tail(nullptr) {}

//Destructor that will clear the nodes
IntList::~IntList() {
    clear();
}


void IntList::clear() {
    while (head != nullptr) {
        pop_front();
    }
}

//Adds new node into the list 
void IntList::push_front(int val) {
    IntNode* newNode = new IntNode(val);
    newNode->next = head;
    head = newNode;
    
    if (tail == nullptr) {
        tail = head;
    }
}


void IntList::pop_front() {
    if (head != nullptr) {
        IntNode* temp = head;
        head = head-> next;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;
        }
    }
}


bool IntList::empty() const {
    return head == nullptr;
}


const int& IntList::front() const {
    return head-> value;
}


const int& IntList::back() const {
    return tail-> value;
}




ostream& operator<<(ostream &out, const IntList& list) {
    
    IntNode* curr = list.head;
    
    while (curr != nullptr) {
        out << curr-> value;

        
        if (curr-> next != nullptr) {
            out << " ";
        }
        
        curr = curr-> next;
    }
    
    return out;
}