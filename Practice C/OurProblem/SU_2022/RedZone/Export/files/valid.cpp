#include "testlib.h"

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    
    const int MXN = 100'000, MXM = 100'000;
    const int MXHouse = 1e9;
    const int MXDmg = 1e4;

    int N = inf.readInt(1, MXN, "N");
    inf.readSpace();
    int M = inf.readInt(1, MXM, "M");
    inf.readSpace();
    int L = inf.readInt(1, N, "L");
    inf.readSpace();
    int D = inf.readInt(1, MXDmg, "D");
    inf.readEoln();


    for (int i = 1; i <= N; i++) {
        inf.readInt(1, MXHouse, "house");
        if (i < N) {
            inf.readSpace();
        }
    }
    inf.readEoln();

    for (int i = 1; i <= M; i++) {
        inf.readInt(1, N, "bomb_pos");
        inf.readEoln();
    }

    inf.readEof();
}