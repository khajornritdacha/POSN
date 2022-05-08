#include<bits/stdc++.h>
using namespace std;
char c[2055][2055];
int cnt,row,col;
bool visit[2055][2055];
vector<pair<int,int>> vec;
queue<pair<int,int>> qq;
void bfs(int x,int y){
    qq.emplace(x,y);
    while(!qq.empty()){
        int ro = qq.front().first;
        int co = qq.front().second;
        qq.pop();
        visit[ro][co] = true;
        int pr[]={-1,-1,-1,0,0,1,1,1},pc[]={-1,0,1,-1,1,-1,0,1};
        for(int i=0;i<8;i++){
            int nr = ro+pr[i];
            int nc = co+pc[i];
            if(nr<1||nc<1||nr>row||nc>col)
                continue;
            if(c[nr][nc]=='0')
                continue;
            if(visit[nr][nc]==true)
                continue;
            visit[nr][nc] = true;
            qq.emplace(nr,nc);
        }
    }
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> row >> col;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cin >>  c[i][j];
            if(c[i][j]=='1')
                vec.emplace_back(i,j);
        }
    }
    for(int i=0;i<vec.size();i++){
        int ro = vec[i].first;
        int co = vec[i].second;
        if(!visit[ro][co]){
            cnt++;
            bfs(ro,co);
        }
    }
    cout << cnt;
    return 0;
}
