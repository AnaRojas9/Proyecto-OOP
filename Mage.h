#ifndef MAGE_H
#define MAGE_H

#include "CombatUnit.h"

class Mage: public CombatUnit{
    private:
        int mana;

    public:
        Mage(string type, int life, int attackpts, int level, int mana);
        int getMana();
        void setMana(int mana);
        void receiveAttack(int attackPoints);
        void attack(CombatUnit &target);
        void print();
};

#endif