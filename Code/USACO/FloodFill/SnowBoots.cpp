#include<bits/stdc++.h>
#define DEBUG false
#define int long long
using namespace std;

const int N = 3e2+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
using lb = long double;

int n,B,mn[N],a[N],S[N],D[N];


void setIO(string name=""){
    ios_base::sync_with_stdio(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

main(){
    setIO("snowboots");
    cin >> n >> B;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        mn[i] = 1e9;
    }
    for(int i=1; i<=B; i++){
        cin >> S[i] >> D[i];
    }

    queue<int> qq;
    mn[1] = 1;
    qq.emplace(1);
    while(!qq.empty()){
        int i = qq.front();
        qq.pop();
        for(int u=mn[i]; u<=B; u++){
            if(S[u] < a[i]) continue;
            for(int k=1; k<=D[u] and i+k<=n; k++){
                if(S[u] >= a[i+k] and mn[i+k] > u){
                    mn[i+k] = u;
                    qq.emplace(i+k);
                }
            }
        }
    }
    cout << mn[n]-1;
}

