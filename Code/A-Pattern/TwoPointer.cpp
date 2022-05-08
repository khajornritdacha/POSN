//find the smallest subarray whose sum is greater or equal to K with 2 pointers technique

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n, K, arr[N];

bool isok(int val){
    return val >= K;
}

int add(int idx, int val){
    return val+arr[idx];
}

int rem(int idx, int val){
    return val-arr[idx];
}

int main(void){
    cin >> n >> K;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    int ans = n+1;
    for(int l = 1, r = 1, cur = 0; r <= n; r++){ //start l and r at 1
        cur = add(r, cur); //add r
        while(l+1 <= r and isok(rem(l, cur))){ //remove l while it is possible
            cur = rem(l, cur); //don't forget to actually remove l
            l++;
        }

        if(isok(cur)){ //check if it can be a candidate for an answer
            ans = min(ans, r-l+1);
        }
    }

    if(ans == n+1) cout << "Impossible\n";
    else cout << ans << "\n";

    return 0;
}