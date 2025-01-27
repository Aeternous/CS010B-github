// Name: (Score was 10/10)
// NetID: 

#include "IntVector.h"

// Implement just this shrink_to_fit function
void IntVector::shrink_to_fit() {
    if (_capacity > _size) {
        _capacity = _size;
    }

    int* _newdata = new int[_capacity];

    for (unsigned int i = 0; i < _size; ++i) {
        _newdata[i] = _data[i];
    }

    delete[] _data;
    _data = _newdata;
}
