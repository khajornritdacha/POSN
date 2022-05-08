#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using ll = long long;
using pi = pair<int, int>;
using lb = long double;

int n;

pi chk(int K){
    int r = 0, cnt = 0;
    for(int i=1; i<=n; i++){
        r += min(n, K/i);
        //printf("I %d = %d\n", i, min(n, K/i));
        if(K/i <= n and K%i == 0)
            cnt++;
    }
    return pi(r-cnt+1, r);
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);// freopen("sabotage.in", "r", stdin); freopen("sabotage.out", "w", stdout);
    cin >> n;
    int l = 1, r = n*n, mid, ans, wa = (n*n)/2+1;
    //cout << "WA : " << wa << "\n";
    while(l <= r){
        mid = (l+r)/2;
        pi tmp = chk(mid);
        //cout << mid << " " << tmp.first << " " << tmp.second << "\n";
        if(tmp.first <= wa and wa <= tmp.second){
            ans = mid;
            break;
        }else if(wa < tmp.first){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
}
