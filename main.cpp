#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include "./Character.hpp"
#include "./Barbarian.hpp"
#include "./Mage.hpp"
#include "./Potion.hpp"
#include "./Exceptions.hpp"
#include "./Monster.hpp"
#include "./Priest.hpp"
#include "./Menu.hpp"


using namespace std;

vector<Character*> Character::charactersList;

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    // Menu m;


    try {

        Menu::start();

        //charcaters
        Mage mage("Mage");
        Barbarian barbarian("Barbarian");
        Priest priest("Priest");
        Monster monster1("monster1");
        Monster monster2("monster2");
        Monster monster3("monster3");

        string characterName;
        string charactersType[3] = {"Mage", "Barbarian", "Priest"};

        // std::vector<Character*> charactersList {&mage, &barbarian, &priest, &monster1, &monster2, &monster3};
        //create characters and select names
        for (int i = 0; i < 3; i++) {
            // m.refresh();
            Menu::devToScreen(
                "",
                "Select a name for your " + charactersType[i] + " character",
                ""
            );

            cout << Menu::endLine;
            cin >> characterName;

            if (i == 0) {
                mage.name = characterName;

            } else if (i == 1) {
                barbarian.name = characterName;

            } else {
                priest.name = characterName;
            }
        }

        //trier par vitesse 

        
        //faire des tours tant que tt le monde n'est pas mort
        // m.turn(Character::charactersList);

        while(!Menu::isEndOfCombat()) {
            Menu::turn();
        }


        



        /* 

        ---code by julien---

        conan.enterFury();
        conan.attack(gandalf);

        conan.attack(gandalf);
        cout << "Gandalf a " << gandalf.getCurrentHp() << " PV" << endl;
        conan.enterFury();

        Potion small(3,100);
    
        gandalf += small;
        gandalf += small;
        gandalf += small;
        cout << "All potions were drunk !" << endl;
        */
    }
    catch(IllegalFury& illegalF){
        cout << "An illegal barbarian fury operation occured : " << illegalF.what() << endl;
    }
    catch(EmptyPotion& ep){
        cout << "An illegal barbarian fury operation occured : " << ep.what() << endl;
    }
    catch(std::exception& e){
        cout << "An exception occured : " << e.what() << endl;
    }

    // cout << "End of combat" << endl;
    Menu::devToScreen("","End of combat","");



    return 0;
}