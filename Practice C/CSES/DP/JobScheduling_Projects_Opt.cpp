#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n;

//use binary search on sequence instead of using map

struct project{
    int st, ed, val;
    bool operator < (const project &o){
        return ed < o.ed;
    }
};

project a[N];

int bi(int val){
    int l = 0, r = n, res = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(a[mid].ed >= val){
            res = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return res;
}


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    
    for(int i = 1;  i<= n; i++){
        cin >> a[i].st >> a[i].ed >> a[i].val;
    }
    
    sort(a+1, a+n+1);

    vector<long long> dp(n+5);
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1];

        int k = bi(a[i].st);

        dp[i] = max(dp[i], dp[k-1] + a[i].val);
    }

    cout << dp[n] << "\n";

    return 0;
}