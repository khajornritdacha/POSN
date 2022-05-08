#include<bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;
int n,res;
bool ed;
vector<tuple<int,int,int>> ans;
map<pair<int,int>, vector<int>> mp;
set<int> ss[150];
void dfs(int u, int p){
    vector<int> chu = mp[{min(u,p), max(u,p)}];
    sort(chu.begin(), chu.end());
    if(u == 'Y')
        ed = true;
    if(p != -1){
        int tmp = (sz(chu)%2 ? 2*chu[sz(chu)/2] : chu[sz(chu)/2]+chu[sz(chu)/2-1]);
        ans.emplace_back(p, u, tmp);
        res+=tmp;
    }
    for(int v : ss[u]){
        if(v!=p)
            dfs(v, u);
    }
}
main(){
    cout << setprecision(1) << fixed;
    cin >> n;
    for(int i=1; i<=n; i++){
        char x,y;
        int c;
        cin >> x >> y >> c;
        if(x>y)
            swap(x,y);
        mp[{x,y}].emplace_back(c);
        ss[x].insert(y);
        ss[y].insert(x);
    }
    dfs('X', -1);
    if(ed){
        for(int i=0; i<sz(ans); i++){
            int x,y,z;
            tie(x,y,z) = ans[i];
            cout << (char)x << " " << (char)y << " " << (float)z/2 << "\n";
        }
        cout << (float)res/2;
    }else{
        cout << "broken";
    }
    cout << "\n";
}
