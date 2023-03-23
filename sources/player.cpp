#include "player.hpp"

#include <string>

#include <iostream>
using namespace std;
using namespace ariel;



Player::Player(string name){
    myName=name;
}

string Player::getName(){
    return myName;
}

int Player::stacksize(){
    return 0;
}

int Player::cardesTaken(){
    return 0;
}  
