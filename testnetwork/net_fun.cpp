#include "net_fun.h"

float sig(float x, float steepness)
{
    return 1.0/ (1 + pow(2.71828, - steepness * x));
}
float sigP(float x, float steepness)
{
    // defined the value of e^(-steepness * x) so the computer
    // wouldnt have to do it three times in the function
    double activation = sig(x,steepness);
    return steepness * activation* (1-activation);
}

float rnum()
{
    //return dis(gen);
    return (float)rand() / RAND_MAX;

}

