#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

using pi = pair<int,int>;
struct DATA{
    int hp,sum;
};

map<pi, DATA> mp[2];
int n,T,F,S,Q,gone,px[]={-1,0,1,0},py[]={0,-1,0,1};

main(){
    cin >> n >> T >> F >> S >> Q;
    for(int i=1; i<=n; i++){
        int x,y,h,v;
        cin >> x >> y >> h >> v;
        DATA tmp;
        tmp.hp = h, tmp.sum = 0;
        mp[v][pi(x,y)] = tmp;
    }

    for(int t=1; t<=T; t++){
        vector<pi> eras;
        for(auto it = mp[1].begin(); it!=mp[1].end(); it++){
            if(--(it->second).hp <= Q){
                eras.emplace_back(it->first);
            }
        }

        if(DEBUG){
            cout << "TIME : " << t << "\n";
            for(auto &[pos, val] : mp[1]){
                cout << pos.first << " " << pos.second << " " << val.hp << " " << val.sum << "\n";
            }
        }

        for(pi er : eras){
            gone++;
            mp[1].erase(er);
        }
        eras.clear();

        for(auto it = mp[1].begin(); it!=mp[1].end(); it++){
            pi pos = it->first;
            DATA val = it->second;
            if(val.hp <= S){
                for(int i=0; i<4; i++){
                    int nx = pos.first+px[i];
                    int ny = pos.second+py[i];
                    if(mp[0].find(pi(nx, ny)) != mp[0].end()){
                        mp[0][pi(nx, ny)].sum += F-val.hp;
                    }
                }
            }
        }

        for(auto it=mp[0].begin(); it!=mp[0].end(); it++){
            if((it->second).sum >= (it->second).hp){
                mp[1][it->first] = it->second;
                eras.emplace_back(it->first);
            }
            (it->second).sum = 0;
        }

        for(pi er : eras)
            mp[0].erase(er);
    }

    cout << mp[1].size() << "\n" << gone << "\n";
}
