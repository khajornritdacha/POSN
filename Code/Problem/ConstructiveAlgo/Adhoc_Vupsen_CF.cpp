#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1582/D

const int N = 1e5+10;

long long arr[N], ans[N], n;

void test_case(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int st = 1;
    if(n&1){
        if(arr[1] + arr[2] != 0){
            ans[1] = ans[2] = -arr[3];
            ans[3] = arr[1] + arr[2];
        } else if(arr[1] + arr[3] != 0){
            ans[1] = ans[3] = -arr[2];
            ans[2] = arr[1] + arr[3];
        } else if(arr[2] + arr[3] != 0){
            ans[2] = ans[3] = -arr[1];
            ans[1] = arr[2] + arr[3];
        }
        st = 4;
    }
    
    for(; st <= n; st += 2){
        ans[st] = arr[st+1];
        ans[st+1] = -arr[st];
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
    
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}