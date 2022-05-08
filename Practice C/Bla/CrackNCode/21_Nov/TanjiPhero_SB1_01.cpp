#include <bits/stdc++.h>
using namespace std;

const int N = 310;
using ll = long long;
int n,a[N][N],b[N][N];

ll cal(){
    ll res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1, k = n; j <= n/2; j++){
            res += 1ll*a[i][j]*(k-j);
            if(a[i][j] != 0) k--;
        }
        for(int j = n, k = 1; j >= n/2+1; j--){
            res += 1ll*a[i][j]*(j-k);
            if(a[i][j] != 0) k++;
        }
    }
    return res;
}

void transpose(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            b[i][j] = a[j][i];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = b[i][j];
        }
    }
}

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    ll res = cal();
    transpose();
    res = max(res, cal());

    cout << res << "\n";
    return 0;
}
