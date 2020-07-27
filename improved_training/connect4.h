#ifndef _CONNECT_4_
#define _CONNECT_4_

#include "Neural_net.h"

using namespace std;

class GameBoard{
    //used for calling any functions of the networks within a game
    Network* learnerP;
    Network* learner2P;

//three two dimentional arrays, representing the state of each slot of the 42 slot board
//first dimention is column, second dimension is row
    bool isEmpty[7][6];
    bool isRed[7][6];
    bool isBlack[7][6];
    float connect4input[7][6];
    int newInputs[6];
//keep track of which of the 7 columns are available (true) and which of the 7 are full (false)
    bool availableSelections[7];
//number of open spaces
    int open;
//what move is it within the game
    int moveNumber;
// did black win?
    bool blackWon;
// is the game over?
    bool isGameOver;
// is it blacks turn?
    bool blacksMove;
//was the game a draw?
    bool isDraw;
// will black be playing as an algorithm, as apoosed to as a network?
    bool blackAlgo;
//used for backpropagation, these have the first dimension of 42 corresponding to as many of the 42 possible moves in a game as necessary,
//stores the input for network, what the network ended up choosing, and what it could have chosen from
    int choiceStorage[42];
    vector<float> inputStorage[42];
    bool availableStorage [42][7];

//used for summary statistics
    int numDiagonalWins;
  int numVerticalWins;
  int numHorizontalWins;
  int numBlackWins;
  int numRedWins;
  int numChoices;

    public:
        GameBoard(){
            initializeGameBoard();
        }

//returning summary statistics from a game
  int getBlackWins(){return numBlackWins;}
  int getRedWins(){return numRedWins;}
  int getVerticalWins(){return numVerticalWins;}
  int getDiagonalWins(){return numDiagonalWins;}
  int getHorizontalWins(){return numHorizontalWins;}
  int getMoveNumber(){return moveNumber;}
  int getNumChoices(){return numChoices;}

  void createBlankFile(string fileName);

//functions to play a game with
  void initializeGameBoard();
  void displayCurrentGameBoard();
  void makeMove(int c);
  void undoMove(int c);
  int makeTurn();
  void getNewInputs(int i);

  void updateNetworks();

  void playCPUGame(){
        initializeGameBoard();
        blackAlgo = false;

        //loads the two networks
        const vector<int> dimensions = {7*6,100,50, 7};
        Network learner("connect4black.net");
        Network learner2("connect4red.net");
        //Network learner(dimensions);
        //Network learner2(dimensions);
        learnerP = &(learner);
        learner2P = &(learner2);

        while(!isGameOver){
        makeTurn();
        moveNumber++;
        }
	    displayCurrentGameBoard();
        updateNetworks();
    }

};

#endif // _CONNECT_4_
