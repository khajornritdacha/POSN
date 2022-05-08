#include<bits/stdc++.h>
using namespace std;
int x[50050],y[50050],n,m,k;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0;i<k;i++){
        int u,v,r;
        cin >> u >> v >> r;
        if(u-r>=0)
            x[u-r]++;
        else
            x[0]++;
        x[u+r+1]--;
        if(v-r>=0)
            y[v-r]++;
        else
            y[0]++;
        y[v+r+1]--;
    }
    int cnt = 0,maxx = 0;
    for(int i=0;i<=n;i++){
        cnt+=x[i];
        maxx = max(maxx,cnt);
        //cout << x[i] << " ";
    }
    //cout << "\n";
    cnt = 0;
    for(int i=0;i<=m;i++){
        cnt+=y[i];
        maxx = max(maxx,cnt);
        //cout << y[i] << " ";
    }
    //cout << "\n";
    cout << maxx;
}
