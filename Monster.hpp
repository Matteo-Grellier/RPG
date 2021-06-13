#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "./Character.hpp"
#include <string>
#include <cstdlib>

using namespace std;

class Monster : public Character {

    public:
    Monster(string name) : Character(name,Job::MonsterJob,250,0,30,800,(60+rand()%50)){}
    void teamAttack();
    void randomAction();

    void launchSpecialAction(Character& c) override;
};

#endif