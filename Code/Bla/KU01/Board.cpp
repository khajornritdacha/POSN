#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
using ll = long long;

int n,m,S,a[N][N];

int main(void){
    cin >> n >> m >> S;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            a[i][j] += (i-1)*S;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            bool ok = true;
            for(int k = i-1; k >= 1; k--){
                if(a[k][j] >= a[i][j]) ok = false;
            }
            cnt += (!ok);
        }
    }
    cout << n*m-cnt << "\n";
    return 0;
}
