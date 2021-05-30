#include "./Potion.hpp"


int Potion::getHealedHp(){
    if(remainingCharges <= 0){
        throw EmptyPotion();
    }
    remainingCharges -= 1;
    return hpPerCharge;
}

bool Potion::operator<(const Potion& p){
    return this->remainingCharges*this->hpPerCharge < p.remainingCharges* p.hpPerCharge;
}