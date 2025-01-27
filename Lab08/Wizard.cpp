#include "Wizard.h" 
#include <iostream> 

using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int rank): Character(WIZARD, name, health, attackStrength) , rank(rank){}

void Wizard::attack(Character &opponent) {
    double damageDone = 0.0;

    if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        damageDone = attackStrength * (static_cast<double>(rank) / opp.rank);
        cout << "Wizard " << getName() << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << damageDone << " damage." << endl;
    }

    else { 
        damageDone = attackStrength;
        cout << "Wizard " << getName() << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << damageDone << " damage." << endl;
    }

    opponent.damage(damageDone);
}