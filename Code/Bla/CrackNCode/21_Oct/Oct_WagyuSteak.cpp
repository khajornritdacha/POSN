#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e5+10;
using ll = long long;

int n,M,Q,a[N],ans[N];

///https://www.hackerrank.com/contests/crack-n-code-october-2021/challenges/wagyu-steak/problem

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> M >> Q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans[i] = 1e9;
    }

    ll sum = 0;
    for(int i = 1, l = 1, r = 0; i <= n; ){
        //cout << i << " " << l << " " << r << "\n";
        while(true){
            //cout << l << " " << r << "\n";
            while(l <= n and sum > M){
                sum -= a[l];
                l++;
            }
            while(r < n and sum < M){
                r++;
                sum += a[r];
            }
            while(l <= n and sum > M){
                sum -= a[l];
                l++;
            }
            if(sum == M or r == n){
                break;
            }
        }

        //cout << i << " " << l << " " << r << "\n";
        //cout << "SUM : " << sum << "\n";
        if(sum == M){
            ans[i] = r;
        }
        if(l == i){
            sum -= a[l];
            l++;
        }
        i++;
    }


    if(DEBUG){
        for(int i = 1; i <= n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    for(int i = 1; i <= Q; i++){
        int l, r; cin >> l >> r;
        if(r >= ans[l]){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}
