#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6+10, INF = 1e9+7;
using ll = long long;
using pi = pair<int,int>;
 
int n,Q,h[N],lef[N],rig[N],pa[N];
ll ans, ansp[N];
bool We[N],Ws[N];
vector<pi> vec,qq;
map<int, int> E,S; //E for end point of subarray, S for start point of subarray
 
int fi(int x){ return pa[x] = (pa[x] == x) ? x : fi(pa[x]); }
 
void rem(int id){    
    int ir = 0, il = 0;
    if(Ws[id+1]){
        ir = fi(id+1);
    }
 
    if(We[id-1]){
        il = fi(id-1);
    }
 
    if (!ir and !il){ //create new subarray
        lef[id] = rig[id] = id;
        Ws[id] = We[id] = true;
        ans += 1;
    } else if(ir and il){ //merge left and right subarray together
        int tsr = rig[ir] - lef[ir] + 1;
        int tsl = rig[il] - lef[il] + 1;
        int tsz = tsr + tsl + 1;
        ans -= 1ll*tsr*(tsr+1)/2; //delete previous ans and add new one later
        ans -= 1ll*tsl*(tsl+1)/2;
        ans += 1ll*tsz*(tsz+1)/2;
        rig[il] = rig[ir];
 
        pa[ir] = il;
        Ws[id+1] = We[id-1] = false;
 
    } else if(ir){
        int tsr = rig[ir] - lef[ir] + 1;
        ans -= 1ll*tsr*(tsr+1)/2;
        ans += 1ll*(tsr+1)*(tsr+2)/2;
        lef[ir]--;
        pa[id] = ir;
 
        Ws[id+1] = false;
        Ws[id] = true;
    } else if(il){      
        int tsl = rig[il] - lef[il] + 1;
        ans -= 1ll*tsl*(tsl+1)/2;
        ans += 1ll*(tsl+1)*(tsl+2)/2;
        rig[il]++;
        pa[id] = il;
 
        We[id-1] = false;
        We[id] = true;
    }
    return;
}
 
int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
        vec.emplace_back(h[i], i);
        pa[i] = i;
    }
 
    for(int i = 1; i <= Q; i++){
        int x; cin >> x;
        qq.emplace_back(x, i);
    }
 
    sort(qq.begin(), qq.end());
    sort(vec.begin(), vec.end());
 
    int vi = 0; //pointer of vector's index
    for(auto [want, iq] : qq){
        while(vi < n and vec[vi].first <= want){
            rem(vec[vi].second);
            vi++;
        }
 
        /*cout << "CHK : " << want << "\n";
        for(int i = 1; i <= n; i++){
            cout << fi(i) << " " << lef[fi(i)] << " " << rig[fi(i)] << "\n";
        }*/
 
        ansp[iq] = ans;
    }
 
    for(int i = 1; i <= Q; i++){
        cout << ansp[i] << "\n";
    }
 
    return 0;
}