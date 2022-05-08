//https://codeforces.com/problemset/problem/1623/C
//Just give everything that i could to i-1 and i-2

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n, arr[N];

inline int ro(int x){
    return x-x%3;
}

void test_case(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int l = 1, r = 1e9, ans = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        bool ok = true;

        vector<int> re(n+5);
        for(int i = n; i >= 3; i--){
            int G = 0;
            if(re[i] >= mid){
                G = ro(arr[i]);
            } else if(re[i] + arr[i] >= mid){
                G = min(ro(re[i]+arr[i]-mid), ro(arr[i]));
            }
        
            re[i-1] += G/3;
            re[i-2] += G/3*2;

            ok &= (arr[i]+re[i]-G >= mid);
        }

        ok &= (arr[1]+re[1] >= mid);
        ok &= (arr[2]+re[2] >= mid);

        if(ok){
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cout << ans << "\n";

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) test_case();
    return 0;
}