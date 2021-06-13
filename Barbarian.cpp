#include "./Barbarian.hpp"
#include "./Menu.hpp"

Barbarian::Barbarian(string name) : Character(name,Job::BarbarianJob,200,0,15,900,80) {
    baseAttack = this->physicalAttack;
    baseDefense = this->defense;
    inFury = false;
}

void Barbarian::enterFury(){
    if( inFury ){
        throw IllegalFury(true);
    }
    baseAttack = this->physicalAttack;
    baseDefense = this->defense;
    inFury = true;
    physicalAttack *= 1.5f;
    defense = 0;
    this->receiveDamage(maxHp*0.15f);

    Menu::toScreen(
        "",
        this->name + " rentre en mode FURY ! il perd donc " + to_string(maxHp*0.15f) + "de vie",
        this->name + " est à " + to_string(this->getCurrentHp()) + " pv."
    );
}

void Barbarian::leaveFury(){
    if(!inFury){
        throw IllegalFury(false);
    }
    physicalAttack = baseAttack;
    defense = baseDefense;
    inFury = false;
}

string Barbarian::getSpecialActionName() {
    if(this->inFury) {
        return "Sortir en Furie";
    } else {
        return "Entrer de Furie";
    }
}

void Barbarian::launchSpecialAction(Character& target) {
    if(inFury) {
        leaveFury();
    } else {
        enterFury();
    }
}