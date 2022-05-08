//https://codeforces.com/contest/1611/problem/F
//there are 2 cases:    1.r pointer moves to right (when we just remove negative number)
//                      2.r pointer moves to left (when we just remove positive number) 
//if it is 2nd case then we just do not move r pointer cuz it cannot improve answer.
#include <bits/stdc++.h>
using namespace std;

void TC(){
    int n, S; cin >> n >> S;
    int arr[n+5] = {};
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    long long sum = S, ret = 0;
    int ar = -1, al = 0;
    for(int l = 1, r = 0; l <= n and r <= n; l++){
        while(r+1 <= n and sum+arr[r+1] >= 0){
            sum += arr[r+1];
            r++;
        }
        if(r-l+1 > ar-al+1){
            ar = r, al = l;
        }
        sum -= arr[l];
    }

    if(ar == -1) cout << "-1\n";
    else cout << al << " " << ar << "\n";

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) TC();

    return 0;
}