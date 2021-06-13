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
vector<Potion*> Character::potionsList;

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    try {

        Menu::start();

        //characters
        Mage mage("Mage");
        Barbarian barbarian("Barbarian");
        Priest priest("Priest");
        Monster monster1("monster1");
        Monster monster2("monster2");
        Monster monster3("monster3");

        Potion bigPotion(1, 300);
        Potion mediumPotion(3, 100);
        Potion littlePotion(6, 50);
        Character::potionsList.push_back(&bigPotion);
        Character::potionsList.push_back(&mediumPotion);
        Character::potionsList.push_back(&littlePotion);

        string characterName;
        string charactersType[3] = {"Mage", "Barbarian", "Priest"};

        //create characters and select names
        for (int i = 0; i < 3; i++) {
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

        
        //faire des tours tant que tt le monde n'est pas mort
        while(!Menu::isEndOfCombat()) {
            Menu::turn();
        }
    }
    catch(IllegalFury& illegalF){
        cout << "An illegal barbarian fury operation occured : " << illegalF.what() << endl;
    }
    catch(EmptyPotion& ep){
        cout << "An illegal drink operation occured : " << ep.what() << endl;
    }
    catch(std::exception& e){
        cout << "An exception occured : " << e.what() << endl;
    }

    Menu::devToScreen("","End of combat","");

    return 0;
}