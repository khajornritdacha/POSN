#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using lb = long double;
using ll = long long;
using pi = pair<int,int>;

int qs[N],a[N],n,K;
///there is a median equal or greater than X if numbers of value that strictly less than X is not more than floor((n-1)/2)
///hence, sum(l, r) <= ((r-l+1)-1)/2; r-l+1 >= K
///qs[r]-qs[l-1] <= (r-l)/2
///2*qs[r]-r <= 2*qs[l-1]-l

bool chk(int mid){
    set<int> ss;
    for(int i=1; i<=n; i++){
        qs[i] = qs[i-1]+(a[i] < mid);
    }
    for(int i=K; i<=n; i++){
        ss.insert(2*qs[i-K]-(i-K+1));
        if(ss.lower_bound(2*qs[i]-i) != ss.end())
            return true;
    }
    return false;
}

void test_case(){
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int l = 1, r = n, ans;
    while(l <= r){
        int mid = (l+r)/2;
        if(chk(mid)){
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
    //cin >> t;
    while(t--){
        test_case();
    }
}
