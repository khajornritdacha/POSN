//https://codeforces.com/problemset/problem/1630/B

#include <bits/stdc++.h>
using namespace std;

void TC(){
    int n, K; cin >> n >> K;
    int arr[n+5] = {}, b[n+5] = {};

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        b[arr[i]]++;
    }

    int ar = n+1, al = 0;
    for(int l = 1, r = 1, sum = -n; r <= n; r++){
        sum += 2*b[r];
        while(l+1 <= r and sum-2*b[l] >= K){
            sum -= 2*b[l];
            l++;
        }
        if(sum >= K and r-l+1 < ar-al+1){
            ar = r, al = l;
        }
    }

    assert(ar != n+1);

    cout << al << " " << ar << "\n";
    int cnt = 0, la = 1;
    for(int i = 1, sum = 0; i <= n; i++){
        sum += (al <= arr[i] and arr[i] <= ar ? 1 : -1);
        if(sum > 0 and cnt+1 < K){
            cout << la << " " << i << "\n";
            la = i+1;
            cnt++;
            sum = 0;
        }
    }

    cout << la << " " << n << "\n";

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) TC();

    return 0;
}