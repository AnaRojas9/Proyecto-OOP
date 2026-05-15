#include "CombatUnit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructores
CombatUnit::CombatUnit() {
    type = "Basic Unit";
    life = 100;
    health = 100;
    attackpts = 10;
    level = 1;
}

CombatUnit::CombatUnit(string type, int life, int attackpts, int level) {
    this->type = type;
    this->life = life;
    this->health = life;
    this->attackpts = attackpts;
    this->level = level;
}


// Getters y Setters
int CombatUnit::get_life() {
    return life;
}

int CombatUnit::get_health() {
    return health;
}

int CombatUnit::get_attackpts() {
    return attackpts;
}

int CombatUnit::get_level() {
    return level;
}

int CombatUnit::set_life(int life) {
    this->life = life;
    return this->life;
}

int CombatUnit::set_health(int health) {
    this->health = health;
    return this->health;
}

int CombatUnit::set_attackpts(int attackpts) {
    this->attackpts = attackpts;
    return this->attackpts;
}

int CombatUnit::set_level(int level) {
    this->level = level;
    return this->level;
}

// Metodos

int CombatUnit::healthPercentage() {
    /*A method that calculates the health percentage. This method must return an int between 0 and 100. 
    It is calculated using the life value (maximum life points) and the health value (current life points).*/
    return (health * 100) / life;
}

void CombatUnit::printHealthBar() {
    /*Method that prints the health bar. The health bar is actually made up of 20 characters that indicate the character’s current 
    health percentage. For example, you may use a % character to represent remaining life and an = character (or any other you choose) 
    to represent lost life. Thus, 80% health could be displayed as: ////////////////----*/
    int percentage = healthPercentage();
    int bars = (percentage*20) / 100; // number of bars displayed
    cout << "[";
    for (int i = 0; i < bars; i++) {
        cout << "/";
    }
    for (int i = bars; i < 20; i++) { // remaining characters (health lost)
        cout << "-";
    }
    cout << "] " << percentage << "%" << endl;
}

void CombatUnit::receiveAttack(int attackPoints) {
    /*Method void receiveAttack(int attackPoints). This method receives a number of points that must be subtracted from the 
    unit’s current health. The health value must never become negative; if it goes below zero, it should be set to zero.*/
    this->health = this->health - attackPoints;
    if(this->health < 0){
        this->health = 0;
    }
}

void CombatUnit::attack(CombatUnit &target){
    int damage = 0;
    int halfattack = this->attackpts/2;

    if (target.get_level()>this->level){

        damage = rand() % halfattack + 1;
    }
    else {
        damage = rand() % (this -> attackpts - halfattack +1) + halfattack;
    }

target.receiveAttack(damage);
    /*Method void attack(Unit& target). This method calculates the attack damage dealt to the target as follows:
     If the target has a higher level than this unit, the attack damage is a random number between 1 and half of 
     the attack points. If the target’s level is lower or equal, the attack damage is a random number between half of the
    attack points and the total attack points. This method must also call the target's receiveAttack method to subtract health
     points from the target.*/
    
}

void CombatUnit::print(){
    cout << "Unit:" <<type<< "Nivel:"<<level<<endl;
    cout << "Life:"<<health<<"/"<<life<<" ";
    printHealthBar();
}
