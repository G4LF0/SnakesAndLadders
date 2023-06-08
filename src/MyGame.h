#include "Dice.h"
#include <iostream>
#include <ctime>
using namespace std;

class MyGame
{
    private:
        int i=0;
        int j=0;
        int num;
        char am;
        int tiles;
        int players;
        int penalty;
        int reward;
        int turns;
        int snakes;
        int stairs;
        char board[100];
        int turn;
        int playerPosition[3];
        int option;
        Dice dice;
    public:
        MyGame();
        void start();
        void fillSL();
        void userEntry();
        void printInstructions();
        bool playTurnPlayer(int);
        void boardExplication();
        void automatic();
        bool automaticTurns(int);
        void menu();
        void printTurn(int,int,int,int,char,int);
};