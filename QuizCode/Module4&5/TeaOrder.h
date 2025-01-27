// Name (First Last): ()
// NetID (e.g., kmill007): 

#include <string>
#ifndef TeaOrder_H
#define TeaOrder_H

class TeaOrder {
private:
    int oz;
    string name;
    string size;
    int cost;

public:
    void ord1(string name1, int sizeOz);
    void ord2(string name2, string sizeName);
    string getname();
    string getsize();
    int getcost();

    void setSize(string sizeName);
    void price(int cost);
};

#endif

/* Write your code here */
