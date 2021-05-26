#ifndef MAGE_HPP
#define MAGE_HPP
#include "./Character.hpp"
#include <string>
#include <cstdlib>

using namespace std;

class Mage : public Character {
    private:
    int mp;
    int maxMp;
    bool tryUsingMp(int mp);

    public:
    Mage(string name) : Character(name,Job::MageJob,15,200,30,1000), maxMp(100), mp(100){}
    void fireball(Character& other);
};

#endif