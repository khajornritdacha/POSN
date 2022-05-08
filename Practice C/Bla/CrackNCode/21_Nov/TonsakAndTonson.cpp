#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

const int N = 1e5+10;
using ll = long long;
using tu = tuple<int,int,int>;
using pi = pair<int,int>;

int n,a[N],fen[2][N],fo[N],bk[N],mx=-1,mn=-1,pmax,pmin;

void up(int idx, int val, int code){
    if(idx == 0) return;
    while(idx <= n){
        fen[code][idx] += val;
        idx += idx&-idx;
    }
}

int sum(int idx, int code){
    int res = 0;
    if(idx == 0) return 0;
    while(idx){
        res += fen[code][idx];
        idx -= idx&-idx;
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        up(i, 1, 0);
    }
    for(int i = 1; i <= n; i++){
        up(a[i], -1, 0);
        fo[i] = sum(a[i], 0);
        bk[i] = sum(n, 1)-sum(a[i], 1);
        up(a[i], 1, 1);

        if(fo[i] > mx){
            mx = fo[i];
            pmax = i;
        }else if(fo[i] == mx and a[i] > a[pmax]){
            pmax = i;
        }

        if(bk[i] > mn){
            mn = bk[i];
            pmin = i;
        }else if(bk[i] == mn and a[i] < a[pmin]){
            pmin = i;
        }
    }

    if(DEBUG){
        cout << "FRONT&BACK\n";
        for(int i = 1; i <= n; i++){
            cout << fo[i] << " " << bk[i] << "\n";
        }
    }

    cout << pmax << " " << pmin << "\n";
    return 0;
}
