#include "MyGame.h"
#include <iostream>
#include <string>
using namespace std;

MyGame::MyGame()
{
    
    srand(time(0));
};
void MyGame::fillSL()
{
    //Posicion de las serpientes en el tablero
    i=0;
    while (i < snakes)
    {
        num=1+(rand()%(tiles-1));
        if(board[num]=='N')
        {
            board[num] = 'S';
            i++;
        }
    }
    //Posicion de las escaleras en el tablero
    i=0;
    while (i < stairs)
    {
        num=1+(rand()%(tiles-1));
        if(board[num]=='N')
        {
            board[num]= 'L';
            i++;
        }
    }
};
void MyGame::start()
{
    while (true)
    {
        menu();
        if(option==1)
        {
            userEntry();
            cout<<"Ingresa si quieres el juego manual o automatico(A/M)"<<endl;
            cin>>am;
            if(am == 'M')
            {
                board[0]='I'; //Error
                board[tiles];
                for(i=1; i<(tiles+1); i++)
                {
                    board[i]='N';
                }
                fillSL();
                //Jugadores
                playerPosition[players];
                for (i = 1; i <=players; i++)
                {
                    playerPosition[i] = 1;
                }
                turn=0;
                for(i = 0; i < (tiles+1); i++)
                {
                    cout<<board[i]<<endl;
                }
                boardExplication();
                printInstructions();
                bool continuePlay = true;
                while (turn <= (turns-1) && continuePlay==true)
                {
                    turn = turn + 1;
                    for (i = 1; i <= players; i++)
                    {
                        continuePlay=playTurnPlayer(i);
                        if(continuePlay==false)
                        {
                            break;
                        }
                        if (playerPosition[i]==tiles)
                        {
                            break;
                        }   
                    }
                }
                if(continuePlay == false)
                {
                    cout<<"THANKS FOR PLAY!!!!"<<endl;
                }
                if(turn > (turns-1))
                {
                    cout<<"THE MAXIMUM NUMBER OF TURNS "<<endl;
                }
                cout<<"GAME OVER"<<endl;
            }
            if(am == 'A')
            {
                cout<<"MODO AUTOMATICO"<<endl;
                automatic();
            }
            else
            {
                cout<<"Escoge una opcion correcta"<<endl;
            }
        }
        if(option==2)
        {
            break;
        }
        else
        {
            cout<<"Escoge una opcion correcta"<<endl;
        } 
    }
};
void MyGame::userEntry()
{
    cout<<"Ingresa el tamano del tablero:"<<endl;
    cin>>tiles;
    cout<<"Ingresa cuantas serpientes quieres en el tablero:"<<endl;
    cin>>snakes;
    cout<<"Ingresa cuantas escaleras quieres en el tablero:"<<endl;
    cin>>stairs;
    cout<<"Ingresa la reduccion de las serpientes:"<<endl;
    cin>>penalty;
    cout<<"Ingresa el aumento de las escaleras"<<endl;
    cin>>reward;
    cout<<"Ingresa cuantos jugadores van a ser:"<<endl;
    cin>>players;
    cout<<"Ingresa el numero de turnos maximo:"<<endl;
    cin>>turns;
    
    
    cout<<"     "<<endl;
}
void MyGame::printInstructions()
{
    cout<<"     Game rules:"<<endl;
    cout<<"Press C to start the game."<<endl;
    cout<<"Press E to exit the game."<<endl;

};
void MyGame::printTurn(int turn, int nPlayer, int originalPosition, int diceRoll, char entry, int finalPosition)
{
    cout<<turn<<"   "<<nPlayer<<"   "<<originalPosition<<"  "<<diceRoll<<"  "<<entry<<" "<<finalPosition<<" "<<endl;
};
void MyGame::boardExplication()
{
    cout<<""<<endl;
    cout<<"↑↑↑Distribution of the board↑↑↑"<<endl;
    cout<<"Explication of the numbers that are displayed each turn:"<<endl;
    cout<<"The fisrt place is the number of turn..."<<endl;
    cout<<"The second place is the number of player..."<<endl;
    cout<<"The third place is the number of the inital position..."<<endl;
    cout<<"The fourth place is the number of dice..."<<endl;
    cout<<"The fifth place is the box type(N,S,L)..."<<endl;
    cout<<"The sixth number is the number of the final position..."<<endl;   
};
bool MyGame::playTurnPlayer(int nPlayer)
{
    char entry;
    cin>>entry;
    while (entry != 'C' && entry!='E')
    {
        cout<<"This option is invalid, please chooce a correct one"<<endl;
        cin>>entry;
    }
    if(entry=='C')
    {
        int diceRoll = dice.roll();
        int originalPosition = playerPosition[nPlayer];
        int newPosition = originalPosition + diceRoll;
        int finalPosition = newPosition;
        if(newPosition > tiles)
        {
            newPosition=tiles;
        }
        if(board[newPosition]=='S')
        {
            finalPosition =  newPosition - penalty;
        }
        if(finalPosition < 1)
        {
            finalPosition = 1;
        }
        if(board[newPosition]=='L')
        {
            finalPosition = finalPosition + reward;
        }
        if(finalPosition > tiles)
        {
            finalPosition = tiles;
        }
        playerPosition[nPlayer] = finalPosition;
        printTurn(turn, nPlayer, originalPosition, diceRoll, board[newPosition], finalPosition);
        if(finalPosition == tiles)
        {
            cout<<"PLAYER:  "<<nPlayer<<"   IS THE WINNER"<<endl;
            return false;
        }
        return true;
    }
    else
    {
        return false;
    }
};
void MyGame::automatic()
{
    board[0]='I'; //Error
    board[tiles];
    for(i=1; i<(tiles+1); i++)
    {
        board[i]='N';
    }
    fillSL();
    //Jugadores
    playerPosition[players];
    for (i = 1; i <=players; i++)
    {
        playerPosition[i] = 1;
    }
    turn=0;
    for(i = 0; i < (tiles+1); i++)
    {
        cout<<board[i]<<endl;
    }
    boardExplication();
    printInstructions();
    bool continuePlay = true;
    while (turn <= (turns-1) && continuePlay==true)
    {
        turn = turn + 1;
        for (i = 1; i <= players; i++)
        {
            //
            int diceRoll = dice.roll();
            //
            continuePlay=automaticTurns(i);
            if(continuePlay==false)
            {
                break;
            }
            if (playerPosition[i]==tiles)
            {
                break;
            }   
        }
    }
    if(continuePlay == false)
    {
        cout<<"THANKS FOR PLAY!!!!"<<endl;
    }
    if(turn > (turns-1))
    {
        cout<<"THE MAXIMUM NUMBER OF TURNS "<<endl;
    }
    cout<<"GAME OVER"<<endl;
};
bool MyGame::automaticTurns(int nPlayer)
{
    int diceRoll = dice.roll();
    int originalPosition = playerPosition[nPlayer];
    int newPosition = originalPosition + diceRoll;
    int finalPosition = newPosition;
    if(newPosition > tiles)
    {
        newPosition=tiles;
    }
    if(board[newPosition]=='S')
    {
        finalPosition =  newPosition - penalty;
    }
    if(finalPosition < 1)
    {
        finalPosition = 1;
    }
    if(board[newPosition]=='L')
    {
        finalPosition = finalPosition + reward;
    }
    if(finalPosition > tiles)
    {
        finalPosition = tiles;
    }
    playerPosition[nPlayer] = finalPosition;
    printTurn(turn, nPlayer, originalPosition, diceRoll, board[newPosition], finalPosition);
    if(finalPosition == tiles)
    {
        cout<<"PLAYER:  "<<nPlayer<<"   IS THE WINNER"<<endl;
        return false;
    }
    return true;
};
void MyGame::menu()
{   
    cout<<""<<endl;
    cout<<"███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗███████╗"<<endl;
    cout<<"██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝██╔════╝"<<endl;
    cout<<"███████╗██╔██╗ ██║███████║█████╔╝ █████╗  ███████╗"<<endl;
    cout<<"╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝  ╚════██║"<<endl;
    cout<<"███████║██║ ╚████║██║  ██║██║  ██╗███████╗███████║"<<endl;
    cout<<"╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝"<<endl;
    cout<<"              █████╗ ███╗   ██╗██████╗ "<<endl;
    cout<<"             ██╔══██╗████╗  ██║██╔══██╗"<<endl;
    cout<<"             ███████║██╔██╗ ██║██║  ██║"<<endl;
    cout<<"             ██╔══██║██║╚██╗██║██║  ██║"<<endl;
    cout<<"             ██║  ██║██║ ╚████║██████╔╝"<<endl;
    cout<<"             ╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝ "<<endl;
    cout<<"██╗      █████╗ ██████╗ ██████╗ ███████╗██████╗ ███████╗"<<endl;
    cout<<"██║     ██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔════╝"<<endl;
    cout<<"██║     ███████║██║  ██║██║  ██║█████╗  ██████╔╝███████╗"<<endl;
    cout<<"██║     ██╔══██║██║  ██║██║  ██║██╔══╝  ██╔══██╗╚════██║"<<endl;
    cout<<"███████╗██║  ██║██████╔╝██████╔╝███████╗██║  ██║███████║"<<endl;
    cout<<"╚══════╝╚═╝  ╚═╝╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝"<<endl;
    
cout<<"                            __..._              "<<endl;
cout<<"                        ..-'      o.            "<<endl;
cout<<"                     .-'            :           "<<endl;
cout<<"                 _..'             .'__..--<     "<<endl;
cout<<"          ...--""                 '-.           "<<endl;
cout<<"      ..-/                        /           "<<endl;
cout<<"    .'                  ___...--'               "<<endl;
cout<<"   :        ____....---'                        "<<endl;
cout<<"  :       .'                                    "<<endl;
cout<<" :       :           _____                      "<<endl;
cout<<" :      :    _..--"""     """--..__             "<<endl;
cout<<":       :  ."                      "i--.       "<<endl;
cout<<":       '.:                         :    '.     "<<endl;
cout<<":         '--...___i---""""--..___.'      :     "<<endl;
cout<<" :                 ""---...---""          :     "<<endl;
cout<<"  '.                                     :      "<<endl;
cout<<"    '-.                                 :       "<<endl;
cout<<"       '--...                         .'        "<<endl;
cout<<"         :   ""---....._____.....---""          "<<endl;
cout<<"         '.    '.                               "<<endl;
cout<<"           '-..  '.                             "<<endl;
cout<<"               '.  :                            "<<endl;
cout<<"                : .'                            "<<endl;
cout<<"               /  :                             "<<endl;
cout<<"             .'   :                             "<<endl;
cout<<"           .' .--'                              "<<endl;
cout<<"          '--'"<<endl;
    cout<<"         ***MENU***            "<<endl;
    cout<<"1.-Play snakes and ladders"<<endl;
    cout<<"2.-Exit"<<endl;
    cin>>option;
};