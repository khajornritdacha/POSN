#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;

int a[N][N],qs[N][N],R,C,Q;

int sum(int r1, int c1, int r2, int c2){
    return qs[r2][c2]-qs[r2][c1-1]-qs[r1-1][c2]+qs[r1-1][c1-1];
}

int main(void){
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
            qs[i][j] = a[i][j]+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]; ///initialize
        }
    }
    cin >> Q;
    while(Q--){
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << sum(r1, c1, r2, c2) << "\n";
    }
    return 0;
}

/*
3 4
1 2 -5 8
11 -3 4 7
-9 6 10 2
3
2 4 3 4
2 2 3 3
2 2 3 4
*/
