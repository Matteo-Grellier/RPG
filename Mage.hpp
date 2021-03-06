#ifndef MAGE_HPP
#define MAGE_HPP
#include "./Character.hpp"
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Mage : public Character {
    private:
    int mp;
    int maxMp;
    bool tryUsingMp(int mp);

    public:
    Mage(string name) : Character(name,Job::MageJob,15,200,30,1000,100), maxMp(100), mp(100) {
        this->hp = 500;
    }
    void fireball(Character& other);

    string getSpecialActionName() override;

    void launchSpecialAction(Character& target) override;
};

#endif