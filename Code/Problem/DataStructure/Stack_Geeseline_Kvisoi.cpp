#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

const int N = 5e6+10, INF = 1e9;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,a[N];
deque<int> dq;

int cal(int i){
    int l = 0, sz = dq.size(), r = sz-1, res = -1;
    while(l <= r){ //we just find the first element that is greater than the current one
        int mid = (l+r)>>1;
        if(dq[mid] > a[i]){
            res = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    if(res == -1){
        if(i == 1) return 0;
        return 1;
    }
    if(dq[res] == 2e9) res++; //out of bound 
    return sz-res;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }    

    ll ans = 0;
    dq.emplace_back(2e9);
    for(int i = 1; i <= n; i++){        
        ans += cal(i); //binary search to find the rightmost elements that current can see
        //cout << cal(i) << " ";
        while(!dq.empty() and a[i] > dq.back()) dq.pop_back(); //dq will always be non increasing order
        dq.emplace_back(a[i]); //dq keep elements that can be seen by its right side. So, if current one is greater than previous one then we have to remove those out
    }
    //cout << "\n";

    cout << ans << "\n";
    return 0;
}
