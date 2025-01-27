#include "Character.h"
#include <iostream>

using namespace std;

//Constructor for the specific character and its stats 
Character::Character(HeroType type, const string &name, double health, double attackStrength) : type(type), name(name), health(health), attackStrength(attackStrength) {}

//This will return the type of character
HeroType Character::getType() const {
    return type;
}
//Returns the name chosen by the user
const string &Character::getName() const {
    return name;
}
//Returns the health
int Character::getHealth() const {
    return health;
}

//Reduces the health based on damage taken 
void Character::damage(double d) {
    health -= d;
    if (health < 0) {
        health = 0;
    }
}

//This will return true or false if the character is alive or not 
bool Character::isAlive() const {
    return health > 0;
}