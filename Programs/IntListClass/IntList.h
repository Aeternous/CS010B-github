#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
    int value;
    IntNode *next;
    IntNode(int value) : value(value), next(nullptr) {}
};

class IntList {
private:
    IntNode *head;
    IntNode *tail;

public:
    IntList();
    ~IntList();

    void clear();
    void push_front(int data);
    void pop_front();
    bool empty() const;
    const int &front() const;
    const int &back() const;

    friend ostream &operator<<(ostream &out, const IntList &list);

    IntList(const IntList &cpy);
    IntList &operator=(const IntList &rhs);

    void push_back(int data);
    void selection_sort();
    void insert_ordered(int data);
    void remove_duplicates();
};

#endif
