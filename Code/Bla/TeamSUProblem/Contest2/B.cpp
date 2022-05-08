#include<bits/stdc++.h>
using namespace std;
int n,m,s,k,a[100100],gg[100100][110];
vector<int> vec[100100];
bitset<100100> chk,chk2;
void ddfs(int u){
    gg[u][a[u]]=0;
    chk[u]=true;
    for(auto v:vec[u]){
        if(chk[v]) continue;
        ddfs(v);
    }
    for(auto v:vec[u]){
        for(int i=1; i<=s; i++){
            gg[u][i]=min(gg[u][i],gg[v][i]+1);
        }
    }
}
void dfs(int u){
    gg[u][a[u]]=0;
    chk2[u]=true;
    for(auto v:vec[u]){
        bool change=false;
        for(int i=1; i<=s; i++){
            if(gg[v][i]>gg[u][i]+1){
                gg[v][i]=gg[u][i]+1;
                change=true;
            }
        }
        if(change||!chk2[v])
            dfs(v);
    }
}
main(){
    cin >> n >> m >> s >> k;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            gg[i][j]=1e9;
        }
    }
    ddfs(1);
    /*for(int i=1; i<=s; i++){
        cout << gg[1][i] << " ";
    }
    cout << "\nV: ";*/
    dfs(1);
    /*cout << "\n\n\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            cout << gg[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";*/
    for(int i=1; i<=n; i++){
        sort(gg[i],gg[i]+s+1);
        long long sum=0;
        for(int j=1; j<=k; j++){
            sum+=gg[i][j];
        }
        cout << sum << " ";
    }
}
