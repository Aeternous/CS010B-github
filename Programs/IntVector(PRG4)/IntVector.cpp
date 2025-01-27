#include "IntVector.h"


using namespace std;

IntVector::IntVector(unsigned capacity, int val) : _size(capacity), _capacity(capacity) {
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


IntVector::~IntVector() {
    delete[] _data;
}

unsigned IntVector::size() const  {
    return _size;
}

unsigned IntVector::capacity() const {
    return _capacity;
}

bool IntVector::empty() const{
    return _size == 0;
}

const int & IntVector::at(unsigned index) const  {
    //Checks if the index given is more than the size (if it is, it will throw it out of range and give an error message)
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}
//This will return the specific index and also check if the index goes over the size which if it does, it will call/throw an out of range error
int & IntVector::at(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

void IntVector::insert(unsigned index, int value)  {
    if(index > _size) {
        throw out_of_range("IntVector::insert_range_check");
    }

    if (_size >= _capacity) {
        expand();
    }
    
    for (unsigned i = _size; i > index; --i) {
        // _data[i + 1] = _data[i];
        _data[i] = _data[i - 1];
    }
    
    _data[index] = value;
    _size += 1; 


}

void IntVector::erase(unsigned index) { 
    if (index >= _size) {
        throw out_of_range("IntVector::erase_range_check");
    }

    for (unsigned i = index; i < _size - 1; ++i) {
        _data[i] = _data[i + 1];
    }

    _size--;
}

const int & IntVector::front() const {
    return _data[0];
}

int & IntVector::front() {
    return _data[0];
}

const int & IntVector::back() const { 
    return _data[_size - 1];
}

int & IntVector::back() {
    return _data[_size - 1];
}
//This will do the same thing as resize but instead of a 0, a value will get passed in
void IntVector::assign(unsigned n, int value) {
    if (n > _capacity) {
        if (_capacity * 2 >= n) {
            expand();
        }
        else {
            expand(n - _capacity);
        }
    }
    
    for (unsigned i = 0; i < n; ++i) {
        _data[i] = value;
    }
    _size = n;
}

void IntVector::push_back(int value) {
    // _size += 1;

    // if (_size > _capacity) {
    //     _capacity *= 2;
    // }
    if (_size == _capacity) {
        expand();
    }

    _data[_size] = value;
    _size++;

}
//Literally just decreases size by 1
void IntVector::pop_back() {

    _size--;

}
//Sets the size of the vector to 0, hence the name clear in the constructor
void IntVector::clear() {
    _size = 0;
}

void IntVector::resize(unsigned n, int value)  {  
    if (n < _size) {
        _size = n;
    }
    
    else if (n > _size) {
        
        if (n > _capacity) {
            if (_capacity * 2 >= n) {
                expand();
            }
            else {
                expand(n - _capacity);
            }
        }
        
        // if (_capacity * 2 >= n){
        //     expand();
        // }
        // else {
        //     expand (n - _capacity);
        // }
    // }

    for (unsigned i = _size; i < n; ++i) {
        _data[i] = value;
    }

    _size = n;
    }

}

//This checks if the capacity is less than n, if it is then it will create a brand new array which then will copy the stuff from the old array into the new one. Then it will delete the old array and udpate everything else to fit with the new array and capacity
void IntVector::reserve(unsigned n) {
    if (n > _capacity ) {
        int* newData = new int[n];

        for (unsigned i = 0; i < _size; ++i) {
            newData[i] = _data[i];
        }

        delete[] _data;
        _data = newData;
        _capacity = n;
    }
}

void IntVector::expand() {
    unsigned _newCapacity;

    if (_capacity == 0) {
        _newCapacity = 1;
    }
    else {
        _newCapacity = _capacity * 2;
    }

    //Creates a new array
    int* _newData = new int[_newCapacity];
    
    //Copies whatever is in the old array into the new array
    for (unsigned i = 0; i < _size; ++i) {
        _newData[i] = _data[i];
    }


    delete[] _data;
    _data = _newData;
    _capacity = _newCapacity;



}

void IntVector::expand(unsigned amount) {
    // _capacity += amount;
    unsigned newCapacity = _capacity + amount;
    int* newData = new int[newCapacity];

    for (unsigned i = 0; i < _size; ++i) {
        newData[i] = _data[i];
    }

    delete[] _data;
    _data = newData;
    _capacity = newCapacity;

}


//New operator dynamically allocates
//Delete deallocates the array

