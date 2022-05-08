#include<bits/stdc++.h>
using namespace std;
int N,M,dis[510][510][1<<3],pr[]={-1,0,0,1},pc[]={0,-1,1,0},mn=1e9;
char a[510][510];
pair<int,int> st,ed;
queue<tuple<int,int,int>> qq;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> a[i][j];
            if(a[i][j]=='S')
                st={i,j};
            if(a[i][j]=='E')
                ed={i,j};
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            for(int k=0; k<(1<<3); k++){
                dis[i][j][k]=1e9;
            }
        }
    }
    dis[st.first][st.second][0]=0;
    qq.emplace(st.first,st.second,0);
    while(!qq.empty()){
        auto [r,c,s]=qq.front();
        qq.pop();
        if(a[r][c]=='E'){
            mn=min(dis[r][c][s],mn);
            continue;
        }
        for(int i=0; i<4; i++){
            int nr=r+pr[i];
            int nc=c+pc[i];
            if(nr<1||nr>N||nc<1||nc>M)
                continue;
            if(a[nr][nc]=='#')
                continue;
            if((a[nr][nc]=='.'||a[nr][nc]=='S')&&dis[r][c][s]+1<dis[nr][nc][s]){
                dis[nr][nc][s]=dis[r][c][s]+1;
                qq.emplace(nr,nc,s);
            }else if(a[nr][nc]=='j'&&dis[r][c][s]+1<dis[nr][nc][s|(1<<0)]){
                dis[nr][nc][s|(1<<0)]=dis[r][c][s]+1;
                qq.emplace(nr,nc,s|(1<<0));
            }
            else if(a[nr][nc]=='b'&&dis[r][c][s]+1<dis[nr][nc][s|(1<<1)]){
                dis[nr][nc][s|(1<<1)]=dis[r][c][s]+1;
                qq.emplace(nr,nc,s|(1<<1));
            }
            else if(a[nr][nc]=='p'&&dis[r][c][s]+1<dis[nr][nc][s|(1<<2)]){
                dis[nr][nc][s|(1<<2)]=dis[r][c][s]+1;
                qq.emplace(nr,nc,s|(1<<2));
            }
            else if(a[nr][nc]=='J'){
                if(s&(1<<0)&&dis[r][c][s]+1<dis[nr][nc][s]){
                    dis[nr][nc][s]=dis[r][c][s]+1;
                    qq.emplace(nr,nc,s);
                }
            }else if(a[nr][nc]=='B'){
                if(s&(1<<1)&&dis[r][c][s]+1<dis[nr][nc][s]){
                    dis[nr][nc][s]=dis[r][c][s]+1;
                    qq.emplace(nr,nc,s);
                }
            }else if(a[nr][nc]=='P'){
                if(s&(1<<2)&&dis[r][c][s]+1<dis[nr][nc][s]){
                    dis[nr][nc][s]=dis[r][c][s]+1;
                    qq.emplace(nr,nc,s);
                }
            }else if(a[nr][nc]=='E'){
                cout << dis[r][c][s]+1;
                return 0;
            }
        }
    }
    /*for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout << dis[i][j][1] << " ";
        }
        cout << "\n";
    }*/
    //cout << (mn!=1e9 ? mn : -1) << "\n";
    cout << -1;
    return 0;
}
