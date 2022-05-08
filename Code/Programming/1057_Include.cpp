#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+100;
int n,cnt[N];
vector<int> vec[N];
bool vi[N],ok;
void dfs(int u){
    cnt[u]++;
    if(vi[u]){
        ok = false;
        return;
    }
    vi[u] = true;
    for(int v : vec[u]){
        dfs(v);
    }
}
void cls(int u){
    vi[u] = false; cnt[u] = 0;
    for(int v : vec[u])
        if(vi[v])
            cls(v);
}
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        for(int j=1; j<=x; j++){
            int y;
            cin >> y;
            vec[i].emplace_back(y);
        }
    }
    for(int i=1; i<=n; i++){
        ok = true;
        dfs(i);
        for(int j=1; j<=n; j++){
            if(cnt[j] > 1)
                ok = false;
        }
        if(!ok)
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
        cls(i);
    }
}
