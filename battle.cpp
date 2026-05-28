#include "CombatUnit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));

    CombatUnit hero("Knight", 100, 30, 5);
    CombatUnit villain("Warrior", 100, 20, 3);

    cout << "Fight Start" << endl;
    hero.print();
    villain.print();

    cout << "The " << hero.type << " attacks " << villain.type << "!" << endl;
    hero.attack(villain);

    villain.print();

    return 0;

}