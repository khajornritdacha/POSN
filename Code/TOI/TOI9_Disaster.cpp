#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> vec[30];
bool visit[30][30];
bool dfs(int u, int lv){
    if(lv==n){
        cout << (char)(u+'A') << " ";
        return true;
    }
    for(auto v : vec[u]){
        if(visit[u][v]){
            visit[u][v]=false;
            visit[v][u]=false;
            if(dfs(v,lv+1)){
                cout << (char)(u+'A') << " ";
                return true;
            }
            visit[u][v]=true;
            visit[v][u]=true;
        }
    }
    return false;
}
main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        int u=str[0]-'A';
        int v=str[1]-'A';
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
        visit[u][v]=true;
        visit[v][u]=true;
    }
    for(int i=0; i<26; i++){
        if(vec[i].size()%2==0) continue;
        if(dfs(i,0)){
            return 0;
        }
    }
    for(int i=0; i<26; i++){
        //if(vec[i].size()%2==0) continue;
        if(dfs(i,0)){
            //cout << (char)(i+'A') << " ";
            return 0;
        }
    }
}
