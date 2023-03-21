#include "player.hpp"

#include <string>


Player::Player(std::string name){
    myName=name;
}

std::string Player::getString(){
    return myName;
}

int Player::stacksize(){
    return 0;
}

int Player::cardesTaken(){
    return 0;
}  
