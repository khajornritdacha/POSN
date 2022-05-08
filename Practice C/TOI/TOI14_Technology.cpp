#include<bits/stdc++.h>
using namespace std;
int N,K,T,cnt,ans=-1;
vector<int> visit;
vector<vector<int>> vec,lv;
void dfs(int);

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> T;
    vec.resize(N+1);
    lv.resize(K+1);
    visit.resize(N+1,0);
    for(int i=1; i<=N; i++){
        int tier,num;
        cin >> tier >> num;
        lv[tier].emplace_back(i);
        for(int j=0; j<num; j++){
            int x;
            cin >> x;
            vec[i].emplace_back(x);
        }
    }
    for(int i=1; i<=K; i++){
        for(auto v:lv[i]){
            if(!visit[v])
                dfs(v);
        }
        if(cnt>T)
            break;
        ans=i;
    }
    cout << ans << "\n";
    return 0;
}

void dfs(int u){
    cnt++;
    visit[u]=2;
    for(auto v:vec[u]){
        if(!visit[v])
            dfs(v);
        else if(visit[v]==2){
            cnt=1e8;
            break;
        }
    }
    visit[u]=1;
}
