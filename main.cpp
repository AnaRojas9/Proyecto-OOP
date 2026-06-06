#include "CombatUnit.h"
#include "Archer.h"
#include "Mage.h"
#include "Warrior.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdexcept> //exception handling

using namespace std;

//Helper function to safely get and validate integer input
int getValidMenuChoice() {
    string input;
    cin >> input;
    
    try {
        size_t pos;
        int choice = stoi(input, &pos);
        
        // If the user types something like "1abc", stoi reads '1' but leaves "abc".
        // This checks if there are trailing non-numeric characters.
        if (pos < input.length()) {
            throw invalid_argument("Trailing characters found.");
        }
        return choice;
        
    } catch (const invalid_argument& e) {
        // Thrown by stoi if no conversion could be performed (user typed "hello")
        throw runtime_error("That is not a valid number.");
    } catch (const out_of_range& e) {
        // Thrown by stoi if the number is too large for an int
        throw runtime_error("That number is too large.");
    }
}

int main(){
    srand(time(NULL));

    // Initialize an interactive scenario
    Archer player("Archer", 100, 25, 5, 30.0, 20);
    Warrior enemy("Enemy Warrior", 150, 20, 3, 25);

    
    cout << "       BATTLE START!       " << endl;
   
    
    // Game loop continues as long as both are alive
    while (player.get_health() > 0 && enemy.get_health() > 0) {
        player.print();
        enemy.print();
        
        cout << "Choose your action:" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Surrender" << endl;
        cout << "> ";
        
        int choice = 0;
        
        try {
            choice = getValidMenuChoice();
            
            // Validate that the number is actually an option on the menu
            if (choice < 1 || choice > 2) {
                throw out_of_range("Choice out of menu bounds."); 
            }
            
            if (choice == 1) {
                cout << "\n Player Turn" << endl;
                player.attack(enemy);
                
                // If the enemy survives, they attack back
                if (enemy.get_health() > 0) {
                    cout << "Enemy Turn" << endl;
                    enemy.attack(player);
                }
            } else if (choice == 2) {
                cout << "\nYou surrendered the battle" << endl;
                break;
            }
            
        } catch (const runtime_error& e) {
            // Catching our custom string errors (not a number, too large)
            cout << "\n[INPUT ERROR] " << e.what() << " Please try again.\n\n";
        } catch (const out_of_range& e) {
            // Catching the menu bounds error (typed 3, 4, 0, etc.)
            cout << "\n[INPUT ERROR] Please enter 1 or 2.\n\n";
        } catch (...) {
            // Catch-all for any other unforeseen exceptions
            cout << "\n[UNKNOWN ERROR] Something went wrong. Try again.\n\n";
        }
    }
    
    
    if (player.get_health() <= 0) {
        cout << "      YOU WERE DEFEATED    " << endl;
    } else if (enemy.get_health() <= 0) {
        cout << "       YOU WON!            " << endl;
    }
    

    return 0;
}
