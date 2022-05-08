#include<bits/stdc++.h>
using namespace std;
using tu = tuple<int,int,int>;
using pi = pair<int,int>;
vector<pi> vec,strip;
vector<tu> use;
vector<bool> mark;
int n,R,D;
double dis(pi a, pi b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
double solve(int l=0, int r=n-1){
    if(l == r)
        return 1e9;
    int mid = (l+r)/2;
    double dl = solve(l, mid);
    double dr = solve(mid+1, r);
    double dm = min(dl, dr);
    for(int i=l; i<=r; i++){
        if(abs(vec[i].first - vec[mid].first) < dm){
            strip.emplace_back(vec[i]);
        }
    }
    sort(strip.begin(), strip.end(), [&](pi &a, pi &b){
        if(a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    });
    for(int i=0; i<strip.size(); i++){
        for(int j=i+1; j<strip.size() and strip[j].second-strip[i].second < dm; j++){
            dm = min(dm, dis(strip[i], strip[j]));
        }
    }
    strip.clear();
    return dm;
}
void test_case(){
    cin >> n >> R >> D;
    vec.clear(); use.clear(); mark.assign(n, false);
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        vec.emplace_back(x, y);
    }
    sort(vec.begin(), vec.end());
    double res = solve();
    cout << (1.0*2*R+D <= res ? "Y" : "N") << "\n";
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
}
