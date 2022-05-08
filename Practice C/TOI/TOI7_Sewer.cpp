#include<bits/stdc++.h>
using namespace std;
char c[105][105];
int n,m,e[105][105];
bool visit[105][105];
deque< pair<int,int> > dq,ans;
main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> c[i][j];
        }
    }
    e[1][1] = 1;
    dq.emplace_back(1,1);
    ans.emplace_back(1,1);
    while(!dq.empty()){
        int i = dq.front().first;
        int j = dq.front().second;
        int nowe = e[i][j];
        dq.pop_front();
        if(i<1||j<1||i>n||j>m)
            continue;
        visit[i][j] = true;
        if((c[i][j]=='B'||c[i][j]=='D')&&visit[i+1][j]==false){
            dq.emplace_back(i+1,j);
            ans.emplace_back(i+1,j);
            e[i+1][j] = nowe+1;
        }
        if((c[i][j]=='B'||c[i][j]=='R')&&visit[i][j+1]==false){
            dq.emplace_back(i,j+1);
            ans.emplace_back(i,j+1);
            e[i][j+1] = nowe+1;
        }
        if(visit[i-1][j]==false&&(c[i-1][j]=='D'||c[i-1][j]=='B')){
            dq.emplace_back(i-1,j);
            ans.emplace_back(i-1,j);
            e[i-1][j] = nowe+1;
        }
         if(visit[i][j-1]==false&&(c[i][j-1]=='R'||c[i][j-1]=='B')){
            dq.emplace_back(i,j-1);
            ans.emplace_back(i,j-1);
            e[i][j-1] = nowe+1;
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size()-1;i++){
        if(ans[i].first==ans[i+1].first&&ans[i].second==ans[i+1].second){
            cout << e[ans[i].first][ans[i].second] << endl << ans[i].first << ' ' << ans[i].second;
            return 0;
        }
    }
}
