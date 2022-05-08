// ./gen1 N M MAX_HP_HOUSE [random string for seed]
// MAX_HP_HOUSE <= 1e4 is recommend for this subtask
// Example (Line below)
// ./gen1 1000 1000 10000 kdsaofjijoewqr;

#include "testlib.h"
#include <iostream>

using namespace std;


int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    // int L = rnd.wnext(N, -10) + 1;
    int L = rnd.next(1, N);
    // const int MAX_DMG = 1e4;
    int D = rnd.next(300, 500);

    cout << N << " " << M << " " << L << " " << D << endl;

    // Gen house
    const int MAX_House = atoi(argv[3]);
    int T = 10;
    for (int i = 1; i <= N; i++) {
        // int house = rnd.wnext(MAX_House, T) + 1;
        int house = rnd.next(1, MAX_House);
        cout << house << (i < N ? " " : "\n");
    }

    // Gen bomb
    for (int i = 1; i <= M; i++) {
        int pos = rnd.next(1, N);
        cout << pos << endl;
    }
}