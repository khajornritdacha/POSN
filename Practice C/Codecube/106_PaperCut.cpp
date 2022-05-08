#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e3+10;
using tu = tuple<int,int,int>;
using pi = pair<int,int>;

int V,H,n,insv[N],insh[N],inev[N],ineh[N];
bool ta[6*N][6*N];
vector<tu> in_hor,in_ver;
vector<int> ver,hor;

void flood(int sv, int sh){
    queue<pi> qq;
    qq.emplace(sv, sh);
    //int pr[]={-1,-1,-1,0,0,1,1,1}, pc[]={-1,0,1,-1,1,-1,0,1};
    int pr[]={-1,1,0,0}, pc[]={0,0,-1,1};
    while(!qq.empty()){
        auto [nr, nc] = qq.front(); qq.pop();
        ta[nr][nc] = true;
        for(int i=0; i<4; i++){
            int gr = nr+pr[i], gc = nc+pc[i];
            if(gr < 0 or gr >= ver.size() or gc < 0 or gc >= hor.size()) continue;
            if(ta[gr][gc]) continue;
            ta[gr][gc] = true;
            qq.emplace(gr, gc);
        }
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> H >> n;
    for(int i=1; i<=n; i++){
        cin >> insv[i] >> insh[i] >> inev[i] >> ineh[i];
        if(insv[i] == inev[i]){
            if(insh[i] > ineh[i]) swap(insh[i], ineh[i]);
            in_hor.emplace_back(insv[i]*2, insh[i]*2, ineh[i]*2);
        }else{
            if(insv[i] > inev[i]) swap(insv[i], inev[i]);
            in_ver.emplace_back(insh[i]*2, insv[i]*2, inev[i]*2);
        }
        ver.emplace_back(insv[i]*2);
        ver.emplace_back(inev[i]*2);
        hor.emplace_back(insh[i]*2);
        hor.emplace_back(ineh[i]*2);
    }
    ver.emplace_back(0);
    hor.emplace_back(0);
    ver.emplace_back(2*V);
    hor.emplace_back(2*H);
    in_ver.emplace_back(0, 0, 2*V);
    in_ver.emplace_back(2*H, 0, 2*V);
    in_hor.emplace_back(0, 0, 2*H);
    in_hor.emplace_back(2*V, 0, 2*H);
    sort(ver.begin(), ver.end());
    sort(hor.begin(), hor.end());
    ver.resize(unique(ver.begin(), ver.end())-ver.begin());
    hor.resize(unique(hor.begin(), hor.end())-hor.begin());

    for(int i=1,sz=ver.size(); i<sz; i++){
        ver.emplace_back(ver[i]-1);
    }
    for(int i=1,sz=hor.size(); i<sz; i++){
        hor.emplace_back(hor[i]-1);
    }
    sort(ver.begin(), ver.end()); sort(hor.begin(), hor.end());
    sort(in_ver.begin(), in_ver.end()); sort(in_hor.begin(), in_hor.end());

    if(DEBUG){
        cout << "VER Point : ";
        for(int v : ver)
            cout << v << " ";
        cout << "\n";
        cout << "HOR Point : ";
        for(int h : hor)
            cout << h << " ";
        cout << "\n";
        cout << "--------------------------\n";
        cout << "In_ver\n";
        for(auto [pos, st, ed] : in_ver){
            cout << pos << " " << st << " " << ed << "\n";
        }
        cout << "--------------------------\n";
        cout << "In_hor\n";
        for(auto [pos, st, ed] : in_hor){
            cout << pos << " " << st << " " << ed << "\n";
        }
        cout << "--------------------------\n";
    }

    for(int i=0; i<in_ver.size(); i++){
        auto [pos, st, ed] = in_ver[i];
        for(int idx=0; idx<hor.size(); idx++){
            if(hor[idx] == pos){
                bool code = false;
                for(int k=0; k<ver.size(); k++){
                    if(st <= ver[k] and ver[k] <= ed){
                        code = true;
                        ta[k][idx] = true;
                    }else if(code){
                        break;
                    }
                }
                break;
            }
        }
    }

    for(int i=0; i<in_hor.size(); i++){
        auto [pos, st, ed] = in_hor[i];
        for(int idx=0; idx<ver.size(); idx++){
            if(ver[idx] == pos){
                bool code = false;
                for(int k=0; k<hor.size(); k++){
                    if(st <= hor[k] and hor[k] <= ed){
                        code = true;
                        ta[idx][k] = true;
                    }else if(code){
                        break;
                    }
                }
                break;
            }
        }
    }

    if(DEBUG){
        for(int i=0; i<ver.size(); i++){
            for(int j=0; j<hor.size(); j++){
                cout << ta[i][j] << " ";
            }
            cout << "\n";
        }
    }

    int ans = 0;
    for(int i=0; i<ver.size(); i++){
        for(int j=0; j<hor.size(); j++){
            if(!ta[i][j]){
                ans++;
                flood(i, j);
            }
        }
    }

    cout << ans << "\n";

}

/*
4 7 6
0 1 4 1
1 0 1 1
2 1 2 3
3 2 3 5
0 3 3 3
2 4 4 4
*/
