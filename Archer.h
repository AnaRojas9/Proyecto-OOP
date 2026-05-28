#ifndef ARCHER_H
#define ARCHER_H

#include "CombatUnit.h"
using namespace std;

class Archer: public CombatUnit{
    private:
        int agility;
        float accuracy;
        
    public:
       Archer(string type, int life, int attackpts, int level, float accuracy, float agility);

       float getAccuracy();
       void setAccuracy(float accuracy);
       int getAgility();
       void setAgility(int agility);
       void receiveAttack(int attackPoints);
       void attack(CombatUnit &target);
       void print();
};

#endif