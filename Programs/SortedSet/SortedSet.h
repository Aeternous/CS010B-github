#ifndef SORTEDSET_H
#define SORTEDSET_H
#include "IntList.h"

#include <iostream>
using namespace std;

class SortedSet : public IntList {
    public:
        SortedSet();
        SortedSet(const SortedSet &CPY);
        SortedSet(const IntList &RHS);
        ~SortedSet();

        bool in(int value) const;
        
        void add(int value);
        void push_front(int value);
        void push_back(int value);
        void insert_ordered(int value);

        SortedSet operator|(const SortedSet &RHS) const;
        SortedSet operator&(const SortedSet &RHS) const;
        SortedSet operator|=(const SortedSet &RHS);
        SortedSet operator&=(const SortedSet &RHS);
};

#endif