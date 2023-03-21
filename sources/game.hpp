#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "iostream"

class Game{

    private:
        Player p1;
        Player p2;

    public:

        Game(){}

        Game(Player p1,Player p2);

        void playAll();

        void printWiner();

        void printLog();

        void printStats();

        void playTurn();

        void printLastTurn();

};


#endif