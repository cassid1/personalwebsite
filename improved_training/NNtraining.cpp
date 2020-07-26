
#include"connect4.h"

int main(){
    srand(time(NULL));
    //bool compGoesFirst = false;
    // other dim {7*6*3,100,75,50, 7};
    const vector<int> dimensions = {7*6,150,75,40, 7};
    GameBoard a;
    //a.playUserGame(compGoesFirst);
    int totalBlackWins = 0;
    int totalRedWins = 0;
    int totalVertWins = 0;
    int totalDiagWins = 0;
    int totalHorizWins = 0;
    int totalChoices = 0;
    int totalMoves = 0;
    for(int i=0; i<10; i++){
        a.playCPUGame();

        totalBlackWins += a.getBlackWins();
        totalRedWins += a.getRedWins();

        totalDiagWins += a.getDiagonalWins();
        totalVertWins += a.getVerticalWins();      
        totalHorizWins += a.getHorizontalWins(); 

        totalChoices += a.getNumChoices();
        totalMoves += a.getMoveNumber();
    }
    cout<<"Black (O) Wins: "<<totalBlackWins<<endl;
    cout<<"Red (X) Wins: "<<totalRedWins<<"\n"<<endl;
    cout<<"Vertical Wins: "<<totalVertWins<<endl;    
    cout<<"Horizontal Wins: "<<totalHorizWins<<endl;
    cout<<"Diagonal Wins: "<<totalDiagWins<<"\n"<<endl;
    cout<<"Total Selections: "<<totalChoices<<endl;
    cout<<"Total Moves: "<<totalMoves<<endl; 
    
    return 1;
}
