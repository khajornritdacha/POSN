#include<bits/stdc++.h>
using namespace std;
int t,n,m,x,y,cnt=0,maxx=0;
bool visit[50000];
vector<int> vec[50000];
void dfs(int z){
    for(int j=0;j<vec[z].size();j++){
        int v = vec[z][j];
        if(visit[v]==false){
            visit[v] = true;
            cnt++;
            dfs(v);
        }
    }
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int z=0;z<t;z++){
        maxx = 0;
        cnt = 0;
        cin >> n >> m;
        for(int i=0;i<m;i++){
            cin >> x >> y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        for(int i=1;i<=n;i++){
            cnt=0;
            if(visit[i]==false)
                dfs(i);
            if(cnt>maxx){
                maxx = cnt;
            }
        }
        cout << maxx << '\n';
        for(int i=1;i<=n;i++){
            visit[i] = false;
        }
        for(int i=1;i<=n;i++){
            vec[i].clear();
        }
    }
    return 0;
}
