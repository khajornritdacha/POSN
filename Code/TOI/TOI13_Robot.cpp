#include<bits/stdc++.h>
#define pi pair<int,int>
#define endl "\n"
using namespace std;
queue<pi> qq;
vector<pi> st,ed;
int row,col,cou[2050][2050],dis,cnt;
char ipt[2050][2050];
bool visit[2050][2050];
main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> row >> col;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cou[i][j] = 1e9;
            cin >> ipt[i][j];
            if(ipt[i][j]=='X'){
                st.emplace_back(i,j);
                qq.emplace(i,j);
                cou[i][j] = 0;
            }else if(ipt[i][j]=='A'){
                ed.emplace_back(i,j);
            }
        }
    }
    while(!qq.empty()){
        pi now = qq.front();
        visit[now.first][now.second] = true;
        qq.pop();
        int pr[]={-1,0,0,1},pc[]={0,-1,1,0};
        for(int i=0;i<4;i++){
            int nr = now.first+pr[i];
            int nc = now.second+pc[i];
            if(nr<1||nc<1||nr>row||nc>col)
                continue;
            if(ipt[nr][nc]=='W'){
                continue;
            }
            if(cou[nr][nc]>cou[now.first][now.second]+1){
                cou[nr][nc] = cou[now.first][now.second]+1;
            }
            if(!visit[nr][nc]){
                qq.emplace(nr,nc);
                visit[nr][nc] = true;
                //cout << nr << " " << nc << " ";
            }
        }
    }
     for(int i=0;i<ed.size();i++){
        pi now = ed[i];
        if(cou[now.first][now.second]!=1e9){
            cnt++;
            dis+=cou[now.first][now.second]*2;
        }
    }
    cout << cnt << " " << dis;
}
