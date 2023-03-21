#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>

namespace ariel{}
using namespace ariel;

using namespace std;


class Player{

    private:
        std::string myName;

    
    public:

        Player(){}

        Player(std::string name);

        std::string getString();

        int stacksize();

        int cardesTaken();   

};

#endif