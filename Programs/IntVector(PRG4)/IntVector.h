#ifndef _INTVECTOR_H_
#define _INTVECTOR_H_

#include <vector>
#include <stdexcept> 
using namespace std;

#include "IntVector.h"

class IntVector {
    public:
    //Old stuff from Lab6
    IntVector(unsigned capacity = 0, int value = 0);
    ~IntVector();
    unsigned size() const;
    unsigned capacity() const;
    bool empty() const;
    const int & at(unsigned index) const;
    int & at(unsigned index);
    void insert(unsigned index, int value);
    void erase(unsigned index);
    const int & front() const;
    int & front();
    const int & back() const;

    //Brand functions/constructors for Program

    int & back();
    void assign(unsigned n, int value);
    void push_back(int value);
    void pop_back();
    void clear();
    void resize(unsigned n, int value = 0);
    void reserve(unsigned n);

    private:
    //Old stuff form Lab6
    unsigned _size;         //This will store the number of elements in a vector
    unsigned _capacity;  //This will hold the real size(capacity) of the vector 
    int* _data;

    //New stuff for Program 6
    void expand();
    void expand(unsigned amount);
};

#endif