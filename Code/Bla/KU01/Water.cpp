#include <bits/stdc++.h>
using namespace std;

const int N = 2020;
using ll = long long;
using pi = pair<int,int>;

int n, L, X, wa[15][N];

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> L >> X;
    L *= 2;
    wa[0][X] = (1<<n);
    for(int i = 0; i < n; i++){
        for(int j = 1; j < L; j++){
            if(!wa[i][j]) continue;
            
            if(j-1 > 0 and j+1 < L){
                wa[i+1][j-1] += wa[i][j]/2;
                wa[i+1][j+1] += wa[i][j]/2;
            } else if (j-1 > 0){
                wa[i+1][j-1] += wa[i][j];
            } else if(j+1 < L){
                wa[i+1][j+1] += wa[i][j];
            } else {
                assert(0);
            }

        }
    }

    for(int j = 1; j < L; j++){
        if(n%2 != 0 and j%2 == 0){
            cout << wa[n][j] << " ";
        } else if(n%2 == 0 and j%2 != 0){
            cout << wa[n][j] << " ";
        }
    }
    cout << "\n";

    return 0;
}