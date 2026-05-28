#include "Mage.h"
#include <iostream>
using namespace std;

Mage::Mage(string type, int life, int attackpts, int level, int mana){
    this->type = type;
    this->set_life(life);
    this->set_health(life);
    this->set_attackpts(attackpts);
    this->set_level(level);
    this->mana = mana;
}

int Mage::getMana(){
    return mana;
}

void Mage::setMana(int mana){
    this->mana = mana;
}

void Mage::receiveAttack(int attackPoints){
    /* the mage can avoid taking the full damage by using mana to create a shield. the strength of said shield depends on the
    amount of mana the mage has and their level. */
    int shield = (mana * get_level()) / 10; // the shield strengthis calculated as mana multiplied by level divided by 10
    cout << type << " used " << mana << " mana to create a shield with " << shield << " strength!" << endl;
    if (shield >= attackPoints) {
        this->mana -= (attackPoints * 10) / get_level(); // if the shield fully blocks the attack, the mages loses mana intead of health
    } else {
        this->set_health(this->get_health() - (attackPoints - shield)); // mage takes any remaining damage the shield didnt block
    }
    cout << type << " received " << attackPoints << " damage." << endl << endl;
}

void Mage::attack(CombatUnit &target){
    /* the mage can use mana to increase the damage of their attack. the amount of extra damage depends on the amount of mana 
    and the mage's level.*/
    int extradmg = (mana * get_level()) / 10; // the extra damage is calculated as mana multiplied by level divided by 10
    cout << type << " used " << mana << " mana to increase the attack!" << endl;
    cout << "The extra damage is " << extradmg << "." << endl;
    int damage = get_attackpts() + extradmg; // the total damage is the base attack points plus the extra damage from mana
    target.receiveAttack(damage);
    this->mana -= extradmg; // reduce the mage's mana by the amount used for the extra damage
    cout << type << " attacked " << target.type << " for " << damage << " damage." << endl << endl;
}

void Mage::print(){
    cout << "Unit:" << type << endl << "Level: "<<get_level()<<endl;
    cout << "Life: "<< get_health() <<"/"<<get_life()<<" ";
    printHealthBar();
    cout << "Mana: " << mana << endl;
    cout << endl << endl;
}