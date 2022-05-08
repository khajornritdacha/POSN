#include <bits/stdc++.h>
using namespace std;

const int N = 510, INF = 1e9;
using ll = long long;
using pi = pair<ll,int>;

//https://www.spoj.com/problems/BOOKS1/

int n,K,a[N];
bool sh[N];

void test_case(){
    cin >> n >> K;
    int mx = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        sh[i] = false;
    }

    ll l = mx, r = 1e12, res = -1;
    while(l <= r){
        ll mid = (l+r)>>1, sum = 0, cnt = 0;
        for(int i = n; i >= 1; i--){
            if(sum + a[i] > mid){
                sum = 0;
                cnt++;
            }
            sum += a[i];
        }

        if(cnt < K){
            res = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    ll sum = 0;
    for(int i = n; i >= 1; i--){
        if(sum + a[i] > res or i < K){ //greedy by let the latter do the most job and leave the leftover job to the previous
            sum = 0;
            sh[i] = true;
            K--;
        }
        sum += a[i];
    }

    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
        if(sh[i]) cout << "/ ";
    }
    cout << "\n";

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while(T--){
        test_case();
    }

    return 0;
}