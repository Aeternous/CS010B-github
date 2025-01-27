// Name (First Last): (Score was 4/20)
// NetID (e.g., kmill007): 

#include "TeaOrder.h"
#include <string>

class TeaOrder {
private:
    int oz;
    string name;
    string size;
    int cost;

public:
    void ord1(string name1, int sizeOz) {
        name = name1;
        oz = sizeOz;
    }

    void ord2(string name2, string sizeName) {
        name = name2;
        size = sizeName;
    }

    string getname() {
        return name;
    }

    string getsize() {
        return size;
    }

    int getcost() {
        return cost;
    }

    void setSize(string sizeName) {
        if (sizeName != "small" && sizeName != "medium" && sizeName != "large") {
            sizeName = "small";
        }
        size = sizeName;
    }

    void price(int cost) {
        if (size == "small") {
            oz = 10;
            cost = oz * 0.20;
        } else if (size == "medium") {
            oz = 14;
            cost = oz * 0.20;
        } else if (size == "large") {
            oz = 20;
            cost = oz * 0.20;
        }
        this->cost = cost;
    }
};
