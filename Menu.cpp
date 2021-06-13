#include "./Menu.hpp"
#include <iostream>
#include <unistd.h>


using namespace std;


void Menu::refresh(){ 
    cout << endLine;
    cout << endLine;
    cout << endLine;

}


void Menu::start(){

    devToScreen(
    "Welcome to the PURPL RPG",
    "   by PURPL STUDIO®",
    "");

    sleep(3);

    loading();

}

void Menu::devToScreen(string line1, string line2, string line3) {
    refresh();
    
    cout << line1 << endl;
    cout << line2 << endl;
    cout << line3 << endl;
}


void Menu::loading(){

    devToScreen("","    .","");
    usleep(300000);

    devToScreen("","    ..","");
    usleep(300000);

    devToScreen("","    ...","");
    usleep(300000);
    
    devToScreen("","","");

}

int Menu::ask(string line1, string line2) {
    
    int answer;

    devToScreen(
    line1,
    line2 + " :",
    " ");

    cout << endLine;
    cin >> answer;

    return answer;

};

// void Menu::turn(vector<Character*> arrayOfCharacters) {

//     for (int i = 0; i < arrayOfCharacters.size(); i++ ) { //for every characters
//         actions( *arrayOfCharacters[i] );

//     }

// }

// void Menu::turn() {
//     string answer = "";
//     for (Character* c : Character::charactersList) {
//         devToScreen(
//             "Attaquer (\"attaque\")",
//             c->getSpecialActionName() + "(\"special\")",
//             "Boire une potion (\"potion\")"
//         );

//         cout << "Que voulez vous faire";
//         cin >> answer;
//     }

//     return;
// }

void Menu::turn() {
    for (Character* c : Character::charactersList) {

        if (!isEndOfCombat()) {
            actions(*c);
        } else {
            return;
        }       
    }
    return;
}

// void Menu::actions(Character& character) {

//     // string isEndCombat = isEndOfCombat();

//     if ( isEndCombat == "win") {
//         end("win");

//     } else if ( isEndCombat == "defeat") {
//         end("defeat");

//     } else {

//         devToScreen(
//         " ",
//         "c'est au tour de " + character.name + " de jouer",
//         " ");

//         sleep(1);

//         if (character.getJob() != "MonsterJob" ){

//             string awnser = ask("| attaquer (\"attaquer\") | " + character.getSpecialActionName() + " (\"classe\") | boire une potion (\"potion\") |", "quel action souhaitez vous effectuer ?");
//             string subAwnser;

//             if (awnser == "attaquer") {
//                 subAwnser = ask(
//                 " ",
//                 "quel personnage souhaitez vous attaquer ?");


//                 // character.attack();


//             } else if (awnser == "classe") {
//                 subAwnser = ask(
//                 " ",
//                 "quel personnage voulez vous viser ?");

//                 // character.launchSpecialAction();

//             } else if (awnser == "potion") {
//                 subAwnser = ask(
//                 " ",
//                 "quel personnage voulez vous viser ?");

//                 // character.drink();

//             } else {
//                 devToScreen(
//                 " ",
//                 "Action inconnu",
//                 " ");

//                 actions(character);

//             }


//         } else {
            

//         }
//     }
// }


string Menu::targetListing() {
    string buffStr = "";
    int buffInt = 0;

    for (Character* c : Character::charactersList) {
        buffStr += " | " + to_string(buffInt) + ". " + c->name;
        buffInt++;
    }

    return buffStr;
}

void Menu::actions(Character& character) {


    devToScreen(
    " ",
    "c'est au tour de " + character.name + " de jouer",
    " ");

    sleep(1);

    if (character.getJob() != 7 ){

        int awnser = ask("| 1. attaquer | 2. " + character.getSpecialActionName() + " | 3. boire une potion |", "quel action souhaitez vous effectuer ?");
        int subAwnser;

        string targetList = targetListing();

        if (awnser == 1) {
            subAwnser = ask(
            targetList,
            "quel personnage souhaitez vous attaquer ?");


            character.attack(*Character::charactersList[subAwnser]);

            devToScreen(
                character.name + " attaque " + Character::charactersList[subAwnser]->name,
                Character::charactersList[subAwnser]->name + " est à " + to_string(Character::charactersList[subAwnser]->getCurrentHp()),
                ""
            );

            // cout << endLine << character.name + " attaque " + Character::charactersList[subAwnser]->name << endl;

            sleep(2);

            // cout << endLine << Character::charactersList[subAwnser]->name + " est à " + to_string(Character::charactersList[subAwnser]->getCurrentHp())<< endl;

            // sleep(2);

        } else if (awnser == 2) {

            if (character.getJob() != 3) {
                subAwnser = ask(
                targetList,
                "quel personnage voulez vous viser ?");

                character.launchSpecialAction(*Character::charactersList[subAwnser]);
            } else {
                character.launchSpecialAction(character);
            }

        } else if (awnser == 3) {
            // subAwnser = ask(
            // " ",
            // "quel personnage voulez vous viser ?");

            // character.drink();

        } else {
            devToScreen(
            " ",
            "Action inconnu",
            " ");

            actions(character);

        }


    } else {
        character.launchSpecialAction(character);
    }
}

bool Menu::isEndOfCombat(){

    int deadGoodGuys = 0;
    int deadMonsters = 0;
    string awnser = "none";

    for (Character* c : Character::charactersList) { //for every characters
        
        if(c->getCurrentHp() <= 0 && c->getJob() != 7) {
            deadGoodGuys++;

        } else if(c->getCurrentHp() <= 0 && c->getJob() == 7) {
            deadMonsters++;

        }

        if (deadMonsters == 3) {
            // awnser = "win"; //necessaire ? appelé end directement ici ??
            end("win");
            return true;

        } else if (deadGoodGuys == 3) {
            // awnser = "defeat";
            end("defeat");
            return true;
        }

    }

    return false;
}

void Menu::end(string endtype){

    if ( endtype == "win") {
        devToScreen(
        "",
        "you won mate, well done !",
        "");
        sleep(1);

    } else if ( endtype == "defeat") {
        devToScreen(
        "",
        "you failed poor noob...",
        "");
        sleep(1);
    }

}
