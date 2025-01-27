#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList() {
    head = tail = nullptr;
}

IntList::~IntList() {
    clear();
}

void IntList::clear() {
    while (head != nullptr) {
        IntNode *temp = head;
        head = head->next;
        delete temp;
    }
    head = tail = nullptr;
}

void IntList::push_front(int value) {
    IntNode *newNode = new IntNode(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void IntList::pop_front() {
    if (head != nullptr) {
        IntNode *temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

bool IntList::empty() const {
    return head == nullptr;
}

const int &IntList::front() const {
    return head->value;
}

const int &IntList::back() const {
    return tail->value;
}

ostream &operator<<(ostream &out, const IntList &list) {
    IntNode *current = list.head;
    while (current != nullptr) {
        out << current->value;
        if (current->next != nullptr) {
            out << " ";
        }
        current = current->next;
    }
    return out;
}

IntList::IntList(const IntList &other) : head(nullptr), tail(nullptr) {
    for (IntNode *current = other.head; current != nullptr; current = current->next) {
        push_back(current->value);
    }
}

IntList &IntList::operator=(const IntList &rhs) {
    if (this != &rhs) {
        clear();
        for (IntNode *current = rhs.head; current != nullptr; current = current->next) {
            push_back(current->value);
        }
    }
    return *this;
}

void IntList::push_back(int value) {
    IntNode *newNode = new IntNode(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void IntList::selection_sort() {
    for (IntNode *i = head; i != nullptr; i = i->next) {
        IntNode *minNode = i;
        for (IntNode *j = i->next; j != nullptr; j = j->next) {
            if (j->value < minNode->value) {
                minNode = j;
            }
        }
        // Swap values of nodes directly
        if (minNode != i) {
            int temp = i->value;
            i->value = minNode->value;
            minNode->value = temp;
        }
    }
}

void IntList::insert_ordered(int value) {
    IntNode *newNode = new IntNode(value);
    if (head == nullptr || value <= head->value) {
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
    } else if (value >= tail->value) {
        tail->next = newNode;
        tail = newNode;
    } else {
        IntNode *current = head;
        while (current->next != nullptr && current->next->value < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void IntList::remove_duplicates() {
    IntNode *current = head;
    while (current != nullptr) {
        IntNode *prev = current;
        IntNode *nextNode = current->next;
        while (nextNode != nullptr) {
            if (nextNode->value == current->value) {
                prev->next = nextNode->next;
                if (nextNode == tail) {
                    tail = prev;
                }
                delete nextNode;
                nextNode = prev->next;
            } else {
                prev = nextNode;
                nextNode = nextNode->next;
            }
        }
        current = current->next;
    }
}
