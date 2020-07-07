//#include "net_fun.h"
//#include "net_fun.cpp"
//#include "Neural_net.h"
//#include "Neural_net.cpp"
#include"connect4.h"
//#include"connect4.cpp"


#include <emscripten/emscripten.h>
#ifdef __cplusplus
extern "C" {
#endif

void EMSCRIPTEN_KEEPALIVE maine(){
    srand(time(NULL));
    bool compGoesFirst = false;
    const vector<int> dimensions = {7*6*3,75,40, 7};
    GameBoard a;
    //this funciton gets information from js radio button,
    //but also within js sets isOurTurn and hasPlayerMoved accordingly
    //and also resets game board
    int JSfirstorsecond = EM_ASM_INT({return JSfirstorsecond();});
    cout << "JSfirstorsecond is: "<<JSfirstorsecond<<endl;
    if (JSfirstorsecond == 1){
        cout<<"user goes first !"<<endl;
        compGoesFirst = false;
    }else{
        cout<<"user goes second !"<<endl;
        compGoesFirst = true;
    }
    a.playUserGame(compGoesFirst);
}
    
#ifdef __cplusplus
}
#endif

