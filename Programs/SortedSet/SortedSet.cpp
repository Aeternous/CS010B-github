#include "SortedSet.h"
#include <iostream>

using namespace std;

SortedSet::SortedSet() : IntList(){
        head = nullptr;
        tail = nullptr;
}

SortedSet::SortedSet(const SortedSet &CPY) : IntList(){
        head = nullptr;
        tail = nullptr;

        IntNode *current = CPY.head;

        while(current != nullptr){
                push_back(current->value);
                current = current->next;
        }
}

/*
SortedSet::SortedSet(const IntList &RHSList) : IntList(){
        head = nullptr;
        tail = nullptr;

        IntList temp = RHSList;

        while(temp.empty()){
                int value = temp.front();
                temp.pop_front();
                temp.push_back(value);
        }
        remove_duplicates();
        selection_sort();
}*/

SortedSet::SortedSet(const IntList &RHSList) : IntList() {
    IntList temp = RHSList; 
    while (!temp.empty()) { 
        int value = temp.front(); 
        add(value); 
        temp.pop_front(); 
    }
}



SortedSet::~SortedSet(){
        clear();
}

bool SortedSet::in(int value) const{
        IntNode *current = head;
        while(current != nullptr){
                if (current->value == value){
                        return true;
                }
                current = current->next;
        }
        return false;
}

void SortedSet::add(int value){
        if (!in(value)){
                IntNode *node1 = new IntNode(value);
                if (head == nullptr){
                        head = node1;
                        tail = node1;
                        return;
                }
                if(value < head->value){
                        node1->next = head;
                        head = node1;
                        return;
                }
                IntNode *current = head;
                IntNode *pastptr = nullptr;

                while(current != nullptr && current->value < value){
                        pastptr = current;
                        current = current->next;
                }
                node1->next = current;
                if(pastptr != nullptr){
                        pastptr->next = node1;
                }
                if(current == nullptr){
                        tail = node1;
                }
        }
}

void SortedSet::push_front(int value){
        add(value);
}
void SortedSet::push_back(int value){
        add(value);
}
void SortedSet::insert_ordered(int value){
        add(value);
}

/*
SortedSet SortedSet::operator|(const SortedSet &RHS) const {
        SortedSet print;

        IntNode *current = head;
        while(current != nullptr){
                print.push_back(current->value);
                current = current->next;
        }
        current = RHS.head;
        while(current != nullptr){
                print.push_back(current->value);
                current = current->next;
        }
        return print;
}
*/
SortedSet SortedSet::operator|(const SortedSet &RHS) const{
    SortedSet print; // Resultant set for the union

    IntNode *current = head; // Traverse this set
    while (current != nullptr) {
        print.add(current->value); // Add elements to result
        current = current->next;
    }

    current = RHS.head; // Traverse RHS set
    while (current != nullptr) {
        print.add(current->value); // Add elements to result
        current = current->next;
    }

    return print;
}

SortedSet SortedSet::operator&(const SortedSet &RHS) const {
        SortedSet print;

        IntNode *current = head;
        while(current != nullptr){
                if(RHS.in(current->value)){
                     print.push_back(current->value);   
                }
                current = current->next;
        }
        return print;
}
/*
SortedSet SortedSet::operator|=(const SortedSet &RHS){
        IntNode *current = RHS.head;

        while(current != nullptr){
                this->add(current->value);
                current = current->next;
        }
        return *this;
}
*/
SortedSet SortedSet::operator|=(const SortedSet &RHS) {
    if (RHS.head == nullptr) { 
        return *this;
    }

    IntNode *current = RHS.head;
    while (current != nullptr) {
        this->add(current->value);
        current = current->next;
    }
    return *this;
}
/*
SortedSet SortedSet::operator&=(const SortedSet &RHS){
        return *this;
}
*/
SortedSet SortedSet::operator&=(const SortedSet &RHS) {
    IntNode *current = head;
    IntNode *previous = nullptr;

    while (current != nullptr) {
        if (!RHS.in(current->value)) { // Remove elements not in RHS
            IntNode *temp = current;
            if (previous != nullptr) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            current = current->next;
            delete temp;
        } else {
            previous = current;
            current = current->next;
        }
    }

    // Update tail pointer
    tail = previous;

    return *this;
}


