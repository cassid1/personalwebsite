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
    const vector<int> dimensions = {7*6*3,75,40, 7};
    GameBoard a;
    //this funciton gets information from js radio button,
    //but also within js sets isOurTurn and hasPlayerMoved accordingly
    //and also resets game board
   int JSfirstorsecond = EM_ASM_INT({JSfirstorsecond()});
   if (JSfirstorsecond == 1){
       bool compGoesFirst = false;
   }else{
       bool compGoesFirst = true;
   }
        a.playUserGame(compGoesFirst);
}
    
#ifdef __cplusplus
}
#endif

