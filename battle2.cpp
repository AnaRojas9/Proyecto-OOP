#include "Mage.h"
#include "warrior.h"
#include "Archer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void showHealth(CombatUnit &unit) {
    cout << "--> " << unit.type << "'s Status | Current Health: " << unit.get_health() << "/" << unit.get_life() << "\n";
}

int main() {
   
    srand(time(NULL));

   
    cout << "(BATTLE 2)";
 
    Mage mage("Dark Mage", 120, 25, 4, 40);

    Warrior warrior("Protector Warrior", 150, 30, 5, 8);

  
    Archer archer("Swift Archer", 100, 28, 4, 35, 30);

    cout << "Initial Units";
    cout << "Mage: " << mage.type << " (Health: " << mage.get_life() << ", Mana: " << mage.getMana() << ")\n";
    cout << "Warrior: " << warrior.type << " (Health: " << warrior.get_life() << ", Strength: " << warrior.get_strength() << ")\n";
    cout << "Archer: " << archer.type << " (Health: " << archer.get_life() << ", Agility: " << archer.getAgility() << "%)\n";
    

    // 2. COMBINATION 1: Mage vs Warrior
    cout << "[COMBAT 1] " << mage.type << " ATTACKS " << warrior.type << endl;
    mage.attack(warrior);
    showHealth(warrior);

    cout << "[COMBAT 2] " << warrior.type << " ATTACKS " << mage.type << endl;
    warrior.attack(mage);
    showHealth(mage);


    // 3. COMBINATION 2: Warrior vs Archer
    cout << "[COMBAT 3] " << warrior.type << " ATTACKS " << archer.type << endl;
    warrior.attack(archer);
    showHealth(archer);

    cout << "[COMBAT 4] " << archer.type << " ATTACKS " << warrior.type << endl;
    archer.attack(warrior);
    showHealth(warrior);


    // 4. COMBINATION 3: Archer vs Mage
    cout << "[COMBAT 5] " << archer.type << " ATTACKS " << mage.type << endl;
    archer.attack(mage);
    showHealth(mage);

    cout << "[COMBAT 6] " << mage.type << " ATTACKS " << archer.type << endl;
    mage.attack(archer);
    showHealth(archer);

    cout << "END OF COMBAT TESTS";
 

    return 0;
}