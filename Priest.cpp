#include <cstdlib>
#include<iostream>
#include "./Priest.hpp"
#include "./Menu.hpp"

using namespace std;
Priest::Priest(string name) : Character(name,Job::PriestJob,25,100,50,200,120), maxMp(100), Mp(100){}

bool Priest::tryUsingMp(int Mp){
    if(this->Mp < Mp){
        return false;
    }
    this->Mp -= Mp;
    return true;
}
    
void Priest::healSpell(Character& other){
    if(!tryUsingMp(this->maxMp*0.10f)){
        return;
    }
    int healValue = (rand() % ( magicAttack*2 - magicAttack)+magicAttack );
    other.heal(healValue);

    Menu::toScreen(
        "",
        this->name + " soigne " + other.name,
        other.name + " est à " + to_string(other.getCurrentHp()) + " pv." 
    );
}

string Priest::getSpecialActionName() {
    if(tryUsingMp(0)) {
        return "Soignez un allié";
    } else {
        return "Soignez un allié (plus assez de point magique...)";
    }
}

void Priest::launchSpecialAction(Character& target) {
    healSpell(target);
}