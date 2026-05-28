#include "Archer.h"
#include <iostream>
#include <string>

using namespace std;

Archer::Archer(string type, int life, int attackpts, int level, float accuracy, float agility){
    this->type = type;
    this->set_life(life);
    this->set_health(life);
    this->set_attackpts(attackpts);
    this->set_level(level);
    this->accuracy = accuracy;
    this->agility = agility;
}

float Archer::getAccuracy(){
    return accuracy;
}

void Archer::setAccuracy(float accuracy){
    /*accuracy is a number indicating the Archer's accuracy percentage, meaning the probability of landing a critical hit. 
    This attribute can increase the amount of damage dealt to a target.*/
    this->accuracy = accuracy;
}

int Archer::getAgility(){
    return agility;
}

void Archer::setAgility(int agility){
    /*agility is a number indicating the Archer's agility percentage, meaning the probability of dodging an attack. 
    This attribute can decrease the amount of damage received from an attack.*/
    this->agility = agility;
}

void Archer::receiveAttack(int attackPoints) {
    /* Derived classes must override the print(), receiveAttack(), and attack() methods. Below are some suggestions for how
     the methods might vary for one of the classes (you will need to decide how they will be modified for each derived class).*/

   // The archer could have a chance to dodge an attack based on agility.
   int chance = rand() % 100;
    if (chance < agility) {
        // for example, if the archer has 30 agility, there is a 30% chance to dodge the attack
         cout << type << " dodged the attack!" << endl << endl;
         return;
    } else {
        set_health(get_health() - attackPoints);
        if (get_health() < 0) {
            set_health(0);
        }
        cout << type << " received " << attackPoints << " damage." << endl << endl;
    }

}

void Archer::attack(CombatUnit &target){
    int damage = 0;
    int halfattack = get_attackpts()/2;
    if (target.get_level()>this->get_level()){
        damage = rand() % halfattack + 1;
    }
    else {
        damage = rand() % (this -> get_attackpts() - halfattack +1) + halfattack;
    }

    int chance = rand() % 100;
    if (chance < this->accuracy) {
        damage *= 2; // critical hit doubles the damage
        cout << type << " landed a critical hit!" << endl;
    }

    target.receiveAttack(damage);
    cout << type << " attacked " << target.type << " for " << damage << " damage." << endl << endl;
}

void Archer::print() {
    cout << "Unit: " << type << endl;
    cout << "Level: " << get_level() << endl;
    cout << "Health: " << get_health() << "/" << get_life() << endl;
    printHealthBar();

    // for the archer, we can also display accuracy and agility
    cout << "Accuracy: " << accuracy << "%" << endl;
    cout << "Agility: " << agility << "%" << endl;
    cout << endl << endl;
}