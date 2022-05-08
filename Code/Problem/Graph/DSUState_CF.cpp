#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
int p[110][110],n,m,q;

int fi(int x, int c){
    if(p[x][c]==x) return x;
    return p[x][c]=fi(p[x][c],c);
}
void uni(int u, int v, int c){
    int hu=fi(u,c);
    int hv=fi(v,c);
    if(p[hu][c]!=p[hv][c]){
        p[hu][c]=p[hv][c];
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            p[i][j]=i;
        }
    }
    for(int i=1; i<=m; i++){
        int u,v,c;
        cin >> u >> v >> c;
        uni(u,v,c);
    }
    cin >> q;
    for(int i=0; i<q; i++){
        int u,v,cnt=0;
        cin >> u >> v;
        for(int j=1; j<=m; j++){
            if(fi(u,j)==fi(v,j))
                cnt++;
        }
        cout << cnt << "\n";
    }
}
/*
https://codeforces.com/contest/505/problem/B
*/
