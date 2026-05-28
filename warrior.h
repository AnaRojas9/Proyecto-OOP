#ifndef WARRIOR_H
#define WARRIOR_H

#include "CombatUnit.h"
#include <string>
using namespace std;

class Warrior : public CombatUnit {
    private:
        int strength; 

    public:
        Warrior();
        Warrior(string type, int life, int attackpts, int level, int strength);

        int get_strength();
        void set_strength(int strength);

        void attack(CombatUnit &target);
        void receiveAttack(int attackPoints);
        void print();
};

#endif


