// ./gen3 N M MAX_HP_HOUSE [random string for seed]
// MAX_HP_HOUSE <= 1e6 is recommended
// Example (Line below)
// ./gen3 100000 100000 1000000 kdsaofjijoewqr;

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
    const int MAX_DMG = 1e4;
    const int MAX_House = atoi(argv[3]);
    // int L = rnd.wnext(N, -10) + 1;
    int L = rnd.next(1, N);
    int D = rnd.next(1, MAX_DMG);

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