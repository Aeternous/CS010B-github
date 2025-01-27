#include "IntVector.h"

using namespace std;

//
IntVector::IntVector(unsigned capacity, int val): _size(capacity), _capacity(capacity) {
    if (_capacity > 0) {
        _data = new int[_capacity];
        for (unsigned i = 0; i < _capacity; ++i) {
            _data[i] = val;
            }
        }
        else {
            _data = nullptr;
        }
    }
//Desctructor that when called will delete the specific array
IntVector::~IntVector() {
    delete[] _data;
}

//Returns size
unsigned IntVector::size() const {
    return _size;
}

//Returns capacity (different from size)
unsigned IntVector::capacity() const {
    return _capacity;
}

//Checks if the vector is empty
bool IntVector::empty() const {
    return _size == 0;
}

//Will check that specific index of the vector
const int & IntVector::at(unsigned index) const {
    //Checks if the index given is more than the size (if it is, it will throw it out of range and give an error message)
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

//Returns the first value of the vector
const int & IntVector::front() const {
    return _data[0];
}

//Returns last value of the vector
const int & IntVector::back() const {
    return _data[_size -1];
}