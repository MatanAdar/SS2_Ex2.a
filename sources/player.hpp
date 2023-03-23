#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>

namespace ariel{}



class Player{

    private:
        std::string myName;

    
    public:

        Player(){}

        Player(std::string name);

        std::string getName();

        int stacksize();

        int cardesTaken();   

};

#endif