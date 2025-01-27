#ifndef IntVector_h
#define IntVector_h

#include <vector>
#include <stdexcept> 

using namespace std;

class IntVector {
    public:
    IntVector(unsigned capacity = 0, int value = 0);
    ~IntVector();


    unsigned size() const;      //Retunrs the size
    unsigned capacity() const;  //Returns the capacity (different from size)
    bool empty() const;         //True or false whether vector is empty or not
    const int & at(unsigned index) const;   //Checks specific index 
    const int & front() const;  //Accesses the first element of the vector
    const int & back() const;   //Accesses the last element of the vector

    private:
    unsigned _size;      //int to be assigned with the size that the user input
    unsigned _capacity;
    int *_data;
};

#endif