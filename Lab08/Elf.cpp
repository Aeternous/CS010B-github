#include "Elf.h"
#include <iostream>

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, const string &familyName) : Character (ELF, name, health, attackStrength), familyName(familyName) {}

//Overriding the attack function for the elf
void Elf::attack(Character &opponent) {
    if (opponent.getType() == ELF ) {
        Elf &opp = dynamic_cast<Elf &>(opponent);

        if (familyName == opp.familyName ) {
            cout << "Elf " << getName() << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << familyName << " family." << endl;
            return;
        }
    }

    double damageDone = (health / MAX_HEALTH) * attackStrength;

    cout << "Elf " << getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
    cout << opponent.getName() << " takes " << damageDone << " damage." << endl;

    opponent.damage(damageDone);

}