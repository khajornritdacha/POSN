#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using lb = long double;
using ll = long long;
using pi = pair<int,int>;
///https://codeforces.com/problemset/problem/818/F
void test_case(){
    int n;
    cin >> n;
    int l = n-1, r = n*n, ans=n-1;
    while(l <= r){
        int mid = (l+r)/2;
        int bridge = (mid+1)/2;
        int edge = mid-bridge;
        int node = n-bridge;
        if(node*(node-1)/2 >= edge and bridge <= n-1){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout << ans << "\n";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
}
