#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e5+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
///https://beta.programming.in.th/tasks/codecube_124
int n,m,pa[N],val[N];
priority_queue<tu, vector<tu>, greater<tu>> qq;

void rem(int a){
    int now = pa[a];
    while(now != -1){
        val[now] -= val[a];
        now = pa[now];
    }
    pa[a] = -1;
}
int fi(int a){
    while(pa[a] != -1){
        a = pa[a];
    }
    return a;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> val[i];
        pa[i] = -1;
    }
    for(int i=1; i<=m; i++){

        //cout << "NOW : " << i << "\n";
        while(!qq.empty() and get<0>(qq.top()) == i){
            auto [wa, a, v] = qq.top(); qq.pop();
            int ha = fi(a);
            val[ha] += v;
        }
        //cout << "PASS\n";

        int code; cin >> code;
        if(code == 1){
            int a; cin >> a;
            rem(a);
        }else if(code == 2){
            int a,b,t,v; cin >> a >> b >> t >> v;
            int ha = fi(a), hb = fi(b);
            if(ha == hb and pa[a] == -1) continue;
            //cout << "CHK : " << ha << " " << hb << "\n";
            rem(a);
            pa[a] = hb;
            val[hb] += val[a];
            qq.emplace(t, a, v);
        }else if(code == 3){
            int a; cin >> a;
            //cout << "FI : " << fi(a) << "\n";
            cout << val[fi(a)] << "\n";
        }

        if(DEBUG){
            for(int i=1; i<=n; i++){
                cout << val[i] << " \n"[i==n];
            }
            cout << "---------------------\n";
        }
    }
}
