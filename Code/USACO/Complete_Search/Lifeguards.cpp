#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int n,ep[N],mx,st[N],ed[N];

main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> st[i] >> ed[i];
    }
    for(int i=1; i<=n; i++){
        int cnt = 0;
        memset(ep, 0, sizeof(ep));
        for(int j=1; j<=n; j++){
            if(j == i) continue;
            ep[st[j]]++;
            ep[ed[j]]--;
        }
        for(int j=0; j<=1000; j++){
            if(j != 0)
                ep[j] += ep[j-1];
            cnt += (ep[j] > 0);
        }
        mx = max(mx, cnt);
    }
    cout << mx;
}

