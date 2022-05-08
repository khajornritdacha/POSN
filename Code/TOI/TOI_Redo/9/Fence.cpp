#include <bits/stdc++.h>
using namespace std;

const int N = 510, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int>;

int R,C,n,qs[N][N],a[N][N];

int sum(int r, int c, int k){
    if(k <= 0) return 0;
    //assert(r-k >= 0 and c-k >= 0);
    return qs[r][c] - qs[r-k][c] - qs[r][c-k] + qs[r-k][c-k];
}

void test_case(){
    cin >> R >> C >> n;
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++){
        int r, c; cin >> r >> c;
        r++, c++;
        a[r][c] = 1;
    }

    for(int i = 1; i <= R; i++) for(int j = 1; j <= C; j++){
        qs[i][j] = qs[i-1][j] + qs[i][j-1] + a[i][j] - qs[i-1][j-1];
    }

    for(int k = min(R, C); k >= 1; k--){
        for(int r = k; r <= R; r++){
            for(int c = k; c <= C; c++){
                int numb = sum(r, c, k), nums = sum(r-1, c-1, k-2);

                if(numb-nums == 0){ //check if the number of black is equal to zero or not
                    cout << k << "\n";
                    return;
                }
                
                //assert(numb-nums >= 0);
            }
        }
    }

    cout << "0\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 2;
    while(t--){
        test_case();
    }

    return 0;
}