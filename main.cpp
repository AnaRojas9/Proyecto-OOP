#include "CombatUnit.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));

    CombatUnit hero("Knight", 100, 30, 5);
    CombatUnit villain("Wizard", 100, 20, 3);

    cout << "Fight Start" << endl;
    hero.print();
    villain.print();

    cout << "The " << hero.type << " attacks " << villain.type << "!" << endl;
    hero.attack(villain);

    // 4. Mostrar resultado
    villain.print();

    return 0;

}