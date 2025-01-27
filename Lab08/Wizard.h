#ifndef WIZARD_H
#define WIZARD_H

#include "Character.h"
#include <iostream>

using namespace std;

class Wizard: public Character {
    public:
    Wizard(const string &name, double health, double attackStrength, int rank);

    void attack(Character &opponent) override;

    private:
    int rank;
};

#endif