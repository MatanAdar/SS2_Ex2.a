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
    Player p3(" ");

    // checking if creating a game not throw exceptions
    CHECK_NOTHROW(Game game(p1,p2));

    Game game(p1,p2);

    //checking if will throw exception before p1 and p2 ended playing the previous game
    //becuase p1 still playing the another game so he cant play new game
    CHECK_THROWS(Game(p1,p2));
    CHECK_THROWS(Game(p1,p3));

    // ending the game
    game.playAll();

    // checking if creating a new game with the players that played before will not throw an exception
    CHECK_NOTHROW(Game game(p1,p3));

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
    CHECK((p1.stacksize()<=21 && p2.stacksize()<=21));

}


TEST_CASE("checking if trying to print winner before game ended"){

    //creating 2 players
    Player p1("Alice");
    Player p2("Bob");

    //starting a game
    Game game(p1,p2);

    // checking if throw exception if trying print winner before game ended
    CHECK_THROWS(game.printWiner());

    game.playAll();

    // after game ended checking if not throwing exception when print winner
    CHECK_NOTHROW(game.printWiner());

}


TEST_CASE("Checking if we have a winner"){ 

    // create 2 players
    Player p1("Alice");
    Player p2("Bob");

    // starting game
    Game game(p1,p2);

    // checking if its throw exception before we even did one move
    CHECK_THROWS(game.printWiner());

    // play one turn
    game.playTurn();

    // Checking if after one turn we didnt played all game and need to throw exception because we dont have winner yet
    // and if the game ended after one turn(everytime had tie and finished all cards before someone won this round),
    // checking if will not throw an exception because we have a winner
    if(p1.stacksize() != 0 || p2.stacksize() != 0){
        CHECK_THROWS(game.printWiner());
    }else{
        CHECK_NOTHROW(game.printWiner());
    }

    // finish the game
    game.playAll();

    bool having_winner=false;;

    // checking if we have a winner(if they have diffrent amout of cardsTaken its mean that someone have more then the other so someone won)
    if(p1.stacksize() == 0 || p2.stacksize() == 0){
        if(p1.cardesTaken()!=p2.cardesTaken()){
            having_winner=true;
        }
    }
    CHECK(having_winner);

}


TEST_CASE("Checking if the players try to play after the game ended"){

    // creating 2 players
    Player p1("Alice");
    Player p2("Bob");

    //starting a game
    Game game(p1,p2);

    //playing the all game until the end
    game.playAll();

    // will throw an error when try to play another turn after the game ended
    CHECK_THROWS(game.playTurn());

    // will throw error try to end the game after we finished the game already
    CHECK_THROWS(game.playAll());
}


TEST_CASE("Checking if game ended"){

    //creating 2 players
    Player p1("Alice");
    Player p2("Bob");

    // starting a game
    Game game(p1,p2);

    // playing the game until the end
    game.playAll();

    // checking if after play all both of players have 0 cards in the stack
    // and checking if they both togheter have 52 in the cardsTaken pille
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
}








