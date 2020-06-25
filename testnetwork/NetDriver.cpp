#include "Neural_net.h"
//#include "Neural_net.cpp"
//#include "net_fun.h"
//#include "net_fun.cpp"

#include <emscripten/emscripten.h>

//TODO:
EMSCRIPTEN_KEEPALIVE
float addNums (float *buffer, int bufSize) {
    float total = 0;
    cout << "we here!";
    for (int i=0; i<bufSize; i++) {
        total+= buffer[i];
    }

    return total;
}

int main()
{
    int myArray [5] = {6, 7, 10, 12, 144};
    //const vector<int> dimentions = {33 * 3, 3, 2};
    const vector<int> dimentions = {3, 3, 2};
    int firstLayer = dimentions[0];
    //srand(time(NULL));

    Network a(dimentions, false, true);
    //    Network a("after.net");

    a.setInputLayer(formToInput("hi", firstLayer, false));
    a.printActivations();
    a.evaluate();
    a.printActivations();
    /**
    vector<float> v = {1, 0};
    cout << "first cost: " << a.cost(v) << endl;
    for (int i = 0; i < 100; i++)
    {
        a -= a.gradient(v);
        a.evaluate();
    }
    cout << "\nlast cost: " << a.cost(v) << endl;
    a.toFile("after.net");
    **/
}