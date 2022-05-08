#include <bits/stdc++.h>
#include "rescuelib.h"
using namespace std;

int main(void){
    int R, C;
    int d[5] = {};
    get_size(R, C);

    d[1] = drop_robot(1, 1);
    d[2] = drop_robot(1, C);
    d[3] = drop_robot(R, 1);
    d[4] = drop_robot(R, C);
    
    int ar = 0, ac = 0;
    if(d[1] != -1 and d[2] != -1){ //hr top
        ar = (d[1]+d[2]-C+3)/2;
        ac = d[1]-ar+2;
    } else if(d[3] != -1 and d[4] != -1){ //hr bottom
        ar = (2*R+C-1-d[3]-d[4])/2;
        ac = d[3]-R+ar+1;
    } else if(d[1] != -1 and d[3] != -1){ //vr left
        ac = (d[1]+d[3]-R+3)/2;
        ar = d[1]-ac+2;
    } else if(d[2] != -1 and d[4] != -1){ //vr right
        ac = (2*C+R-1-d[2]-d[4])/2;
        ar = d[2]-C+ac+1;
    } else {
        assert(0);
    }
   
    answer(ar, ac);
    return 0;
}