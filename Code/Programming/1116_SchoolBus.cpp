#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+10;
using pi = pair<int,int>;
int n,a[N],ans;
vector<pi> vec;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << setprecision(6) << fixed;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    vec.emplace_back(0,0);
    for(int i=1; i<=n; i++){
        if(a[i]*2 >= vec.back().first){
            vec.emplace_back(a[i]*2, a[i]);
            continue;
        }
        int last = vec.back().second, now;
        while(!vec.empty()){
            last = max(last, vec.back().second);
            now = a[i]+last;
            if(now < vec.back().first)
                vec.pop_back();
            else
                break;
        }
        vec.emplace_back(now,last);
    }
    for(auto &[x,y] : vec){
        //cout << x << " " << y << "\n";
        ans = max(ans, abs(2*y-x));
    }
    cout << (long double)ans/2;
}
