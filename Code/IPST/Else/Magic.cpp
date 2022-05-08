#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;

struct DATA{
    int w, v, d, x;
};

//be careful when change type 3 weight : there are some cases in which type 3 is already deleted and we should not insert it back

int n, m, idx = 0;
set<pi> ss, era;
DATA rem[N];

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int t = 0; t < n+m; t++){
        while(!era.empty() and era.begin()->first == t){
            int id = era.begin()->second;
            pi tmp = pi(rem[id].w, rem[id].v);
            if(ss.find(tmp) != ss.end()){
                ss.erase(tmp);
                if(rem[id].x != 0) 
                    ss.insert(pi(rem[id].x, rem[id].v));
            }
            era.erase(era.begin());
        }
        
        int c1; cin >> c1;

        if(c1 == 1){
            int c2; cin >> c2;

            int w, v; cin >> w >> v;
            ss.insert(pi(w, v));

            if(c2 == 2){
                int d; cin >> d;
                
                rem[++idx] = {w, v, d, 0};
                era.insert({d, idx});
            } else if (c2 == 3){
                int d, w2; cin >> d >> w2;
                
                rem[++idx] = {w, v, d, w2};
                era.insert({d, idx});
            }
        } else {
            if(!ss.empty()){
                cout << ss.begin()->second << "\n";
                ss.erase(ss.begin());
            } else {
                cout << "0\n";
            }
        }
    }

    return 0;
}