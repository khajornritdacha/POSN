//https://beta.programming.in.th/tasks/toi11_labor
#include <bits/stdc++.h>
using namespace std;

using pi = pair<int,int>;
const int N = 1e6+10;
using ll = long long;

int n,a[N];
ll K;

bool check(ll mid){
    ll tmp = 0;
    for(int i = 1; i <= n; i++){
        tmp += mid/a[i];
    }
    return (tmp >= K);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }    

    //Binary search an answer
    ll l = 1, r = 1e18, ans = -1;
    while(l <= r){
        ll mid = (l+r)/2;
        if (check(mid)) { //Check if mid value could be an answer
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    
    cout << ans << "\n";
    return 0;   
}