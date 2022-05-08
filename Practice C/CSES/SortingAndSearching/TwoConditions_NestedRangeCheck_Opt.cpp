#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

const int N = 2e5+10;
using tu = tuple<int,int,int>;
using ll = long long;
using pi = pair<int,int>;

int n,st[N],ed[N],idx[N],ans[N][2];

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> st[i] >> ed[i];
        idx[i] = i;
    }

    //3 6, 3 5
    sort(idx+1, idx+n+1, [&](const int &i, const int &j){
        if(st[i] != st[j]) return st[i] < st[j];
        return ed[i] > ed[j];
    });

    int mx = 0; //check if it is inside some ranges
    for(int i = 1; i <= n; i++){
        if(mx >= ed[idx[i]]) 
            ans[idx[i]][1] = 1;
        else
            mx = ed[idx[i]];
    }

    int mn = 2e9; //check if it contains some ranges
    for(int i = n; i >= 1; i--){
        if(mn <= ed[idx[i]])
            ans[idx[i]][0] = 1;
        else 
            mn = ed[idx[i]];
    }

    for(int t : {0, 1}){
        for(int i = 1; i <= n; i++){
            cout << ans[i][t] << " ";
        }
        cout << "\n";
    }

    return 0;
}