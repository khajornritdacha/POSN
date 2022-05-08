#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using lb = long double;
using ll = long long;
using pi = pair<int,int>;
///https://codeforces.com/problemset/problem/1223/C

int n,a[N],qs[N],lc,X,Y,xm,ym,WA;

int sum(int l, int r){
    if(l > r) return 0;
    if(l <= 0) return qs[r];
    return qs[r]-qs[l-1];
}

bool chk(int K){
    int s1 = sum(1, K/lc)/100*(X+Y);
    int s2 = max( sum(K/lc+1, K/xm)/100*X + sum(K/xm+1, K/xm+K/ym-K/lc)/100*Y, sum(K/lc+1, K/ym)/100*Y + sum(K/ym+1, K/ym+K/xm-K/lc)/100*X);
    //printf("%lld %lld %lld\n", s1, s2, s1+s2);
    //printf("%lld %lld %lld\n", sum(K/lc+1, K/xm), sum(K/xm+1, K/ym), sum(K/lc+1, K/ym), sum(K/ym+1, K/xm));
    return ((s1+s2) >= WA);
}

void test_case(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1, greater<int>());
    for(int i=1; i<=n; i++){
        qs[i] = qs[i-1]+a[i];
    }
    cin >> X >> xm >> Y >> ym >> WA;
    lc = xm/__gcd(xm, ym)*ym;

    //printf("LCM(%d, %d) = %d\n", xm, ym, lc);
    int l = 1, r = n, mid, ans=-1;
    while(l <= r){
        mid = (l+r)/2;
        //printf("MID : %d\n", mid);
        if(chk(mid)){
            r = mid-1;
            ans = mid;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";

    //printf("\n\n");
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
}
