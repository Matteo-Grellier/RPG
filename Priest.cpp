#include <cstdlib>
#include<iostream>
#include "./Priest.hpp"

using namespace std;
Priest::Priest(string name) : Character(name,Job::PriestJob,25,100,50,200), maxMp(100), Mp(100){}

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
    cout<<"vie rendu"<<healValue;
    other.heal(healValue);
}