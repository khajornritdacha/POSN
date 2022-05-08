#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,m,ans=1;
vector < pii > vec[100005];
bool visit[100005];
main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y,c;
        cin >> x >> y >> c;
        vec[x].push_back({y,c});
        vec[y].push_back({x,c});
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<vec[i].size();j++){
            int now = vec[i][j].first;
            if(vec[now].size()>2&&visit[now]==false){
                cout << now << endl;
                ans+=1;
            }
            else if(vec[now][0].second!=vec[i][j].second){
                cout << now << endl;
                ans+=1;
            }
        }
        visit[i] = true;
    }
    cout << ans;
}
