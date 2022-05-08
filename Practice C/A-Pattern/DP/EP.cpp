#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M = 1e5+10;
int ep[M],now,n,lim;

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int st,ed;
        cin >> st >> ed;
        ep[st]++;
        ep[ed+1]--;
        lim = max(lim, ed+1); ///O(n+m)
    }
    for(int i=1; i<=lim; i++){
        now += ep[i];
        cout << now << " ";
    }
}
/*
6
1 6
2 10
5 13
3 4
1 6
5 12
*/
