#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

#include "doctest.h"
#include "iostream"
#include <stdio.h>
#include <string>

using namespace ariel;
using namespace std;


TEST_CASE("Checking if player is created fully"){

    //checking if player created successfully without problems
    CHECK_NOTHROW(Player p1("Alice"));
    
    Player p1("Alice");

    //checking if the functions not throwing exceptions
    CHECK_NOTHROW(p1.stacksize());
    CHECK_NOTHROW(p1.cardesTaken());

    // checking if the arguments when created is 0
    CHECK(p1.cardesTaken() == 0);
    CHECK(p1.stacksize() == 0);

}

TEST_CASE("Checking if game created successfully"){

    Player p1("Alice");
    Player p2("Bob");

    // checking if creating a game not throw exceptions
    CHECK_NOTHROW(Game game(p1,p2));
}


TEST_CASE("Checking if function created successfully in game class"){

    //creating 2 players
    Player p1("Alice");
    Player p2("Bob");

    //starting a game
    Game game(p1,p2);

    // checking if all functions not throwing exceptions
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("Checking if the players try to play after the game ended"){

    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    //playing the all game until the end
    game.playAll();

    // will throw an error when try to play another turn after the game ended
    CHECK_THROWS(game.playTurn());

    // will throw error try to end the game after we finished the game already
    CHECK_THROWS(game.playAll());
}


TEST_CASE("Amount of cards the players got before starting the game"){

    // create 2 players
    Player p1("Alice");
    Player p2("Bob");

    // starting game
    Game game(p1,p2);

    // checking if both players have 26 cards at start of the game
    CHECK(p1.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.stacksize() == 26);
    CHECK(p2.cardesTaken() == 0);
   
}

TEST_CASE("Checking if the first turn ended"){

    // create players
    Player p1("Alice");
    Player p2("Bob");

    //start game
    Game game(p1,p2);

    //play 1 turn
    game.playTurn();

    //checking if we still have cards in our hands:
    //if we have, we check if we got cards from the another player(thats mean that someone won)
    //if we dont have cards in our hand , its mean that we had equal cards everytime and then we check if we realy didnt got any card from the another player
    if(p1.stacksize()!=0 && p2.stacksize()!=0){
        CHECK((p1.cardesTaken()>0 || p2.cardesTaken()>0));
    }
    else{
        CHECK((p1.cardesTaken() == 0 && p2.cardesTaken() == 0));
    }

}


TEST_CASE("Checking if after 5 turns the 2 players together have still 52 cards"){

    // create 2 players
    Player p1("Alice");
    Player p2("Bob");

    // starting game
    Game game(p1,p2);

    //playing 5 turns
    for(int i=0;i<5;i++){
        game.playTurn();
    }

    bool amount_of_cards = false;
    
    // checking if both stacksize and cardsTaken of both players togheter is 52
    if(((p1.stacksize()+p1.cardesTaken()) + (p2.stacksize()+p2.cardesTaken())) == 52){
        amount_of_cards=true;
    }

    CHECK(amount_of_cards);
}


TEST_CASE("Checking if we have a winner"){ 

    // create 2 players
    Player p1("Alice");
    Player p2("Bob");

    // starting game
    Game game(p1,p2);

    // finish the game
    game.playAll();

    bool having_winner=false;;

    // checking who won
    if(p1.stacksize() == 0 || p2.stacksize() == 0){
        if(p1.cardesTaken()!=p2.cardesTaken()){
            having_winner=true;
        }
    }
    CHECK(having_winner);

}




TEST_CASE("Checking if game ended"){

    //creating 2 players
    Player p1("Alice");
    Player p2("Bob");

    // starting a game
    Game game(p1,p2);

    // playing the game until the end
    game.playAll();

    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
}








