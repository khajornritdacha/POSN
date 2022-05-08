#include<bits/stdc++.h>
using namespace std;
const int R = 201, C = 201;
using tu = tuple<int,int,int,int>;
int n,m,gem[R][C],sx,sy,cnt,ans=1e9,p[R][C][1<<7][7], pr[]={-1,0,0,0,1}, pc[]={0,-1,0,1,0},jo[1<<7];
char a[R][C];
queue<tu> qq;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'S'){
                sx = i, sy = j;
            }
            if(a[i][j] == 'G'){
                gem[i][j] = (1<<cnt++);
            }
            for(int k=0; k<(1<<7); k++) for(int l=1; l<7; l++) p[i][j][k][l]=1e9;
        }
    }
    for(int i=0; i<(1<<7); i++){
        for(int j=0; j<7; j++)
            if(i&(1<<j))
                jo[i]++;
    }
    p[sx][sy][0][1] = 0;
    qq.emplace(sx,sy,0,1);
    int nr,nc,ng,nt;
    while(!qq.empty()){
        tie(nr,nc,ng,nt) = qq.front();
        //cout << nr << " " << nc << " " << ng << " " << nt << "\n";
        qq.pop();
        if(ng == 127){
            ans = min(ans, p[nr][nc][ng][nt]);
            break;
        }
        int gg = ng, gt = nt+1;
        if(a[nr][nc] == 'G'){
            gg |= gem[nr][nc];
        }
        if(gt == 7){
            gt = 1;
        }
        for(int i=0; i<5; i++){
            int gr = nr+pr[i], gc = nc+pc[i];
            if(gr<1 or gr>n or gc<1 or gc>m)
                continue;
            if(a[gr][gc] == '#')
                continue;
            if(p[gr][gc][gg][gt] != 1e9)
                continue;
            if(a[gr][gc] >= '1' and a[gr][gc] <= '6'){
                if(gt == a[gr][gc]-'0' or jo[gg] >= a[gr][gc]-'0'){
                    if(p[gr][gc][gg][gt]==1e9){
                        p[gr][gc][gg][gt] = p[nr][nc][ng][nt]+1;
                        qq.emplace(gr,gc,gg,gt);
                    }
                }
            }else{
                if(p[gr][gc][gg][gt]==1e9){
                    p[gr][gc][gg][gt] = p[nr][nc][ng][nt]+1;
                    qq.emplace(gr,gc,gg,gt);
                }
            }
        }
    }
    if(ans == 1e9)
        ans = -1;
    else
        ans--;
    cout << ans << "\n";
}
