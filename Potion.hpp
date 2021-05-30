#ifndef POTION_HPP
#define POTION_HPP
#include "./Exceptions.hpp"

class Potion {
    int remainingCharges;
    int hpPerCharge;

    public :
    Potion(int remainingCharges,int hpPerCharge) : remainingCharges(remainingCharges), hpPerCharge(hpPerCharge) {}
    int getHealedHp();
    bool operator<(const Potion& p);
};

#endif