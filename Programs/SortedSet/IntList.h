#ifndef INTLIST_H
#define INTLIST_H

#include <ostream>

using namespace std;

struct IntNode {
	int value;
	IntNode *next;
	IntNode(int value) : value(value), next(nullptr) { }
};

class IntList {

 protected:

	IntNode *head;
	IntNode *tail;

 public:

	IntList();
	IntList(const IntList &);
	IntList & operator=(const IntList &);
	~IntList();
	const int & front() const;
	const int & back() const;
	bool empty() const;
	void push_front(int);
	void push_back(int);
	void pop_front();
	void selection_sort();
	void insert_ordered(int);
	void remove_duplicates();
	void clear();
	friend ostream & operator<<(ostream &, const IntList &);

};

#endif