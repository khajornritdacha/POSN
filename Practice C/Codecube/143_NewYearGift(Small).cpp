#include<bits/stdc++.h>
using namespace std;

const int N = 3e4+10;
int n,T,deg[N],cnt;

main(){
    cin >> n >> T;
    for(int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    for(int i=1; i<=n; i++){
        if(deg[i] == 1)
            cnt++;
    }
    cout << (cnt+1)/2;
}
