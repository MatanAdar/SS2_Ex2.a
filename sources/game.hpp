#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "iostream"

namespace ariel{
class Game{

    private:
        Player player1;
        Player player2;

    public:

        Game(){}

        Game(Player player1,Player player2);

        void playAll();

        void printWiner();

        void printLog();

        void printStats();

        void playTurn();

        void printLastTurn();

};
}


#endif