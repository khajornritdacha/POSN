#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int qs[N][N],qst[N][N],a[N][N],R,C,K;

int cal(){
    int res = -2e9;
    for(int i = 1; i <= R; i++){
        int sum = 0;
        for(int j = 1; j <= C; j++){
            sum += a[i][j];
            qst[i][j] = qst[i-1][j-1] + sum;
            qs[i][j] = qs[i-1][j] + qs[i][j-1] + a[i][j] - qs[i-1][j-1];
        }
    }

    for(int i = K; i <= R; i++){
        for(int j = K; j <= C; j++){
            //cout << i << " " << j << " = " << qst[i][j] - qs[i][j-K] + qs[i-K][j-K] - qst[i-K][j-K] << "\n";
            res = max(res, qst[i][j] - qs[i][j-K] + qs[i-K][j-K] - qst[i-K][j-K]);
        }
    }

    return res;
}


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> K;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
        }
    }

    int ans = cal();

    for(int i = 1; i <= R; i++){
        for(int j = 1, lim = C/2; j <= lim; j++){
            swap(a[i][j], a[i][C-j+1]);
        }
    }

    ans = max(ans, cal());

    cout << ans << "\n";
    return 0;   
}