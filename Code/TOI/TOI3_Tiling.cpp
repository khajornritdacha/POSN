#include<bits/stdc++.h>
using namespace std;
int sz,u,d,mr,ml,a[30][30],pr[]={-1,1,0,0},pc[]={0,0,-1,1},n,ans;
bool vi[30][30];
void dfs(int r, int c){
    if(vi[r][c]) return;
    vi[r][c] = true;
    sz++, u = min(u, r), d = max(d, r), ml = min(ml, c), mr = max(mr, c);
    for(int i=0; i<4; i++){
        int gr=r+pr[i], gc=c+pc[i];
        if(gr < 1 or gr > n or gc < 1 or gc > n) continue;
        if(!vi[gr][gc] and a[gr][gc] == a[r][c])
            dfs(gr, gc);
    }
}
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!vi[i][j] and a[i][j] != 0){
                sz = 0, u = 1e9, d = 0, ml = 1e9, mr = 0;
                dfs(i, j);
                //cout << "NOW : " << i << " " << j << "-> " << sz << " " << u << " " << d << " " << ml << " " << mr << "\n";
                if(sz == 3 and abs(u-d) == 1 and abs(ml-mr) == 1)
                    ans++;
            }
        }
    }
    cout << ans << "\n";
}
