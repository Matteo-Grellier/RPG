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

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    Menu m;


    try {

        m.start();

        // m.simpleText("heyyy");
        // sleep(1);
        // m.loading();
        // m.toScreen(
        // "   ",
        // "         (╯°□°）╯︵ ┻━┻",
        // "   ");
        // m.loading();

        Mage mage("Mage");
        Barbarian barbarian("Barbarian");
        Priest priest("Priest");
        //Monster monster1("monster1");
        //Monster monster2("monster2");
        //Monster monster3("monster3");

        string characterName;
        string charactersType[3] = {"Mage", "Barbarian", "Priest"};

        for (int i = 0; i < 3; i++) {
            string charactersType[3] = {"Mage", "Barbarian", "Priest"};
            characterName = m.ask("", "Select a name for your " + charactersType[i] + " character");

            if (i == 0) {
                mage.name = characterName;

            } else if (i == 1) {
                barbarian.name = characterName;

            } else {
                priest.name = characterName;
            }
        }

        m.actions(mage);

        //creer les monstres 

        //choix des tours

        // m.actions(mage);

        



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
    m.simpleText("End of combat");



    return 0;
}