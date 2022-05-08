// ./gen2 N M MAX_HP_HOUSE [random string for seed]
// MAX_HP_HOUSE <= 1e4 is recommended (should not exceed upperbound of D)
// Example (Line below)
// ./gen2 100000 100000 10000 kdsaofjijoewqr;

#include "testlib.h"
#include <iostream>
#include <utility>

using namespace std;

pair<int, int> pos_range(int idx, const int M, const int N) { 
    if (idx <= M/2) {
        return {N/2, N};
    }
    return {1, N/2};
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    int L = rnd.wnext(N, -10) + 1;
    // int L = rnd.next(1, N);
    // const int MAX_DMG = 1e4;
    const int MAX_House = atoi(argv[3]);
    int D = MAX_House;

    cout << N << " " << M << " " << L << " " << D << endl;

    // Gen house
    int T = 10;
    for (int i = 1; i <= N; i++) {
        int house = rnd.next(1, MAX_House);
        cout << house << (i < N ? " " : "\n");
    }

    // Gen bomb
    for (int i = 1; i <= M; i++) {
        int l, r;
        tie(l, r) = pos_range(i, M, N);
        int pos = rnd.next(l, r);
        cout << pos << endl;
    }
}