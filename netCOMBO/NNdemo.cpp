
#include"connect4.h"
#include "GAN.h"

#include <emscripten/emscripten.h>

#ifdef __cplusplus
extern "C" {
#endif

void EMSCRIPTEN_KEEPALIVE main_connect4(){
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

#ifdef __cplusplus
extern "C" {
#endif

void EMSCRIPTEN_KEEPALIVE main_frankGAN()
{
    //sets random seed to the current time
    srand(time(NULL));

    //declaring istream of the book i downloaded
    ifstream frank("frankenstein.txt");
    string frankstring, line, s;
    s = " ";
    //converts the text into one giant string, turning newlines into spaces
    while (frank)
    {
        getline(frank, line);
        frankstring += s;
        frankstring += line;
    }
    //this was calculated separately
    int CHARS_IN_FRANKENSTEIN = 422874;

    //len is length of phrase to produce. if a net is being read in, this variable is unused.
    int len = 50;
    vector<int> dims = {20, len * 33, 20, 2};


    GAN frankGAN("GANpresentation.net");
    
    
    

    //all info for how big of steps along gradient is taken, how big the subsets of training data is,
    //various variable that affect learning
    int rounds = 1, subset = 10, correct = 0, attempted = 0;
    float discrate = 0.010, genrate = 1, chaosrate= 0.0;

    for (int i = 0; i < rounds; i++)
    {
        //makes two gans to hold the gradient values of each part of the net
        GAN discgrad(frankGAN.getLayerSizes(), 1, false);
        GAN gengrad(frankGAN.getLayerSizes(), 1, false);

        //fake data
        for (int i = 0; i < subset; i++)
        {
            attempted++;
            frankGAN.setInputLayer();
            frankGAN.evaluate();

            if (frankGAN.getOutput(0) < frankGAN.getOutput(1))
                correct++;

            //optimize the discriminator to interpret that content as fake next time
            discgrad += frankGAN.discriminatorGradient(vector<float>{0,1}, 0.5);

            //optimize the generator to make more real-looking content next time
            gengrad += frankGAN.generatorGradient(vector<float>{1,0},0.2);


            
        }
        //real data
        for (int i = 0; i < subset; i++)
        {
            attempted++;
            frankGAN.setContentLayer(extractString(frankstring, rand() % CHARS_IN_FRANKENSTEIN, len));
            frankGAN.evaluate();

            //optimizes the discriminator to interpret that content as real next time
            discgrad += frankGAN.discriminatorGradient(vector<float>{1, 0}, 0.5);

            if (frankGAN.getOutput(0) > frankGAN.getOutput(1))
                correct++;
        }
        //scaling steps, then taking a walk backwards along the corresponding gradients.
        discgrad *= discrate;
        gengrad *= genrate;
        frankGAN -= discgrad;
        frankGAN -= gengrad;

        //extra little nudge to the value decided entirely at random. currently chaosrate is 0 so there is not effect.
        Network chaos(frankGAN.getLayerSizes(), true);
        chaos *= chaosrate;

        frankGAN+= chaos;

        //prints stuff from the user, how stuff looks and the rate (0-1) of how often the discriminator is correctly classifying data
        frankGAN.setInputLayer();
        frankGAN.evaluate();

        //sending the output to JS
        const char * str = frankGAN.getContentLayer().c_str();
        EM_ASM(update_generated_sentence(UTF8ToString($0)), str);
        double percent = (double)correct / attempted;
        EM_ASM({update_disc_data($0);}, percent);
        cout << frankGAN.getContentLayer() << "    ("<< (float)correct / attempted << " discriminated)" <<endl;
    }


    //saves the training session.
    //frankGAN.toFile("GANpresentation.net");
}

#ifdef __cplusplus
}
#endif