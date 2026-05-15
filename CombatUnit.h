#ifndef COMBATUNIT_H
#define COMBATUNIT_H

#include <string>
using namespace std;

class CombatUnit {  // clase base para las unidades de combate
    private:
    int life;       // vida total
    int health;     // vida actual
    int attackpts;     // puntos maximos de ataque
    int level;      // nivel, mientras mas alto sea, mas fuertes son los ataques

    public:
        string type;    // tipo de unidad

        CombatUnit();   // constructor
        CombatUnit(string type, int life, int attack, int level);   // constructor con parametros

        // getters
        int get_life();
        int get_health();
        int get_attackpts();
        int get_level();

        // setters
        int set_life(int life);
        int set_health(int health);
        int set_attackpts(int attackpts);
        int set_level(int level);

        // metodos
        int healthPercentage();
        void printHealthBar();
        void receiveAttack(int attackPoints);
        void attack(CombatUnit &target);
        void print();

};

#endif