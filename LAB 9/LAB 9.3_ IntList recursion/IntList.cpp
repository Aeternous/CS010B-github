#include "IntList.h"

#include <iostream>

using namespace std;

IntList::IntList() : head(nullptr) {}

bool IntList::exists(int val) const {
    return exists(head, val);
}

void IntList::push_front(int val) {
    IntNode *temp = new IntNode(val);
    temp->next = head;
    head = temp;
}

bool IntList::exists(IntNode *Node, int val) const {
    if (Node == nullptr) { 
        return false;
    } else if (Node->value == val) {
        return true;
    } else {
        return exists(Node->next, val); // Recursive call
    }
}

ostream& operator<<(ostream &out, IntNode *Node) {
    if (Node != nullptr) { 
        out << Node->value;
        if (Node->next != nullptr) { 
            out << " ";
        }
        out << Node->next; 
    }
    return out;
}

ostream& operator<<(ostream &out, const IntList &list) {
    out << list.head; 
    return out;
}
