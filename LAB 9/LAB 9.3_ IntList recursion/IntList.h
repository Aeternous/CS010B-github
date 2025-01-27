#ifndef __INTLIST_H__
#define __INTLIST_H__

#include <ostream>

using namespace std;

struct IntNode {
    int value;
    IntNode *next;
    IntNode(int value) : value(value), next(nullptr) {}
};


class IntList {

 private:
   IntNode *head;

 public:
   IntList();
   void push_front(int);
   friend ostream & operator<<(ostream &, const IntList &);
   bool exists(int) const;

 private:
   bool exists(IntNode *, int) const;
};

ostream & operator<<(ostream &, IntNode *);


#endif