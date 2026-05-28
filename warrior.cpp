#include "warrior.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Constructor por defecto
Warrior::Warrior() : CombatUnit("Warrior", 150, 30, 5){
    this->strength = 5;
}

// Constructor con parámetros
Warrior::Warrior(string type, int life, int attackpts, int level, int strength) : CombatUnit(type, life, attackpts, level){
    this->strength = strength;
}

int Warrior::get_strength(){
    return this->strength;
}

void Warrior::set_strength(int strength){
    this->strength = strength;
}

void Warrior::attack(CombatUnit &target){
    int damage = 0; 
    int halfattack = this->attackpts / 2; 

    if (target.get_level() > this->level){
        damage = rand() % halfattack + 1;
    } else {
        damage = rand() % (this->attackpts - halfattack + 1) + halfattack; 
    }

    int finalDamage = damage + this->strength;

    cout << "Damage base: " << damage << " + Force: " << this->strength << " = Final damage: " << finalDamage << endl;
    target.receiveAttack(finalDamage);
}

void Warrior::receiveAttack(int attackPoints){
    int mitigatedDamage = attackPoints - this->strength;

    if (mitigatedDamage < 0) {
        mitigatedDamage = 0;
    }

    cout << "The " << this->type << " blocked " << this->strength << " of damage thanks to their strength. Actual damage received: " << mitigatedDamage << endl;

    this->health = this->health - mitigatedDamage;
    if (this->health < 0) {
        this->health = 0;
    }
} 

void Warrior::print(){ // <--- AHORA SÍ ESTÁ FUERA
    cout << "Unit: " << type << " | Level: " << get_level() << endl;
    cout << "Life: " << get_health() << "/" << get_life() << " ";
    printHealthBar();
    cout << "Strength (Defense/Attack Enhancer): " << strength << endl << endl;
} 