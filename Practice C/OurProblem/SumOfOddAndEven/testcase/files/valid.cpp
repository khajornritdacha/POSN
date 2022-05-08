#include <iostream>
#include "testlib.h"
using namespace std;


int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    int cnt = 0;
    while(true){
        int n = inf.readInt(-100, 100, "n");
        inf.readEoln();
        cnt++;
        if(n == 0){
            break;
        }
        ensuref(-100 <= n && n <= 100, "Integer sth");
        
        if(cnt > 10000){
            ensuref(cnt <= 10000, "Input exceeds limitation with %d", cnt);
        }
    }

    inf.readEof();

    return 0;
}