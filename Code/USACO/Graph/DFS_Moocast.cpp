#include<bits/stdc++.h>
using namespace std;

const int N = 2e2+10;
int n,x[N],y[N],p[N],cnt,mx;
bool vi[N];

void dfs(int u){
    vi[u] = true;
    cnt++;
    //cout << u << "\n";
    for(int i=1; i<=n; i++){
        //cout << "I : " << i << " = " << p[u] << " " << abs(x[i]-x[u])+abs(y[i]-y[u]) << "\n";
        if(!vi[i] and p[u]*p[u] >= abs(x[i]-x[u])*abs(x[i]-x[u])+abs(y[i]-y[u])*abs(y[i]-y[u])){
            dfs(i);
        }
    }
}

void setIO(string name=""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

main(){
    setIO("moocast");
    cin >> n;
    for(int i=1; i<=n;  i++){
        cin >> x[i] >> y[i] >> p[i];
    }
    for(int i=1; i<=n; i++){
        cnt = 0;
        //cout << "ST : " << i << "\n";
        memset(vi, 0, sizeof(vi));
        dfs(i);
        mx = max(mx, cnt);
        //cout << "\n";
    }
    cout << mx << "\n";
}
