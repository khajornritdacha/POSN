#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
char c[55][55];
pii st,ed;
int r,co,t[55][55];
bool visit[55][55];
queue < pair<pii,int> > qq;
main(){
    cin >> r >> co;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=co;j++){
            cin >> c[i][j];
            if(c[i][j]=='S'){
                st = {i,j};
            }else if(c[i][j]=='D'){
                ed = {i,j};
            }else if(c[i][j]=='*'){
                qq.push({{i,j},1});
            }
        }
    }
    t[st.first][st.second] = 1;
    qq.push({{st.first,st.second},2});
    while(!qq.empty()){
        int row = qq.front().first.first;
        int col = qq.front().first.second;
        int code = qq.front().second;
        visit[row][col]=true;
        if(c[row][col]=='D'&&code==2){
            cout << t[row][col]-1;
            return 0;
        }
        qq.pop();
        int pr[]={-1,0,0,1},pc[]={0,-1,1,0};
        for(int i=0;i<4;i++){
            int nr = pr[i]+row;
            int nc = pc[i]+col;
            if(nr<1||nc<1||nr>r||nc>co)
                continue;
            if(visit[nr][nc]==true)
                continue;
            if(c[nr][nc]=='X')
                continue;
            if(c[nr][nc]=='D'&&code==1)
                continue;
            visit[nr][nc]=true;
            qq.push({{nr,nc},code});
            if(code==2){
                t[nr][nc] = t[row][col]+1;
            }

        }
    }
    cout << "KAKTUS";
    return 0;
}
