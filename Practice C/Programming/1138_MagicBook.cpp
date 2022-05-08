#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
using pi = pair<int,int>;
const int N = 1e5+10;
int n,K,S,ans,tr[2*N],x[N],a[N],dp[N];
vector<pi> vec;
int query(int l, int r){
    int tmp = 0;
    for(l+=n-1, r+=n-1; l<=r; l/=2, r/=2){
        if(l%2 == 1){
            tmp = max(tmp, tr[l++]);
        }
        if(r%2 == 0){
            tmp = max(tmp, tr[r--]);
        }
    }
    return tmp;
}
void up(int idx, int val){
    idx+=n-1;
    tr[idx] = val;
    for(idx/=2; idx; idx/=2){
        tr[idx] = max(tr[idx*2], tr[idx*2+1]);
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K >> S;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> a[i];
        vec.emplace_back(x[i], i);
    }
    sort(vec.begin(), vec.end());
    for(int i=n; i>=1; i--){
        dp[i] = a[i];
        int r = upper_bound(vec.begin(), vec.end(), make_pair(x[i]+K, 100000000))-vec.begin();
        int l = lower_bound(vec.begin(), vec.end(), make_pair(x[i]-K, 0))-vec.begin();
        if(r!=0)
            r--;
        dp[i]+=query(l+1, r+1);
        int idx = lower_bound(vec.begin(), vec.end(), make_pair(x[i], i))-vec.begin();
        //cout << "IDX : " << i << " " << l << " " << r << " " << idx << "\n";
        up(idx+1, dp[i]);
    }

    if(DEBUG){
        cout << "VEC : ";
        for(auto [x,y] : vec)
            cout << x << " " << y << "\n";
        cout << "DP : ";
        for(int i=1; i<=n; i++)
            cout << dp[i] << " \n"[i==n];
    }
    for(int i=1; i<=n; i++){
        if(abs(S-x[i]) <= K){
            ans = max(ans, dp[i]);
        }
    }
    cout << ans;
}
