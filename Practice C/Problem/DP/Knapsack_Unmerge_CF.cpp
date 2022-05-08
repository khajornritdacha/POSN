#include <bits/stdc++.h>
using namespace std;

const int N = 2020;
int n, a[2*N];
bool dp[N];

//https://codeforces.com/problemset/problem/1381/B
//see as knapsack problem
//if a[i] is greater than a[i+1] that means a[i] and a[i+1] has to be in the same group
//that means if a[i] is greater than a[i+1], a[i+2], ..., a[j] ; j <= 2*n then a[i], a[i+1], ..., a[j] has to be in the same group

void test_case(){
    cin >> n;
  
    for(int i = 1; i <= 2*n; i++){
        cin >> a[i];
    }
    
    vector<int> vec;
    for(int i = 1; i <= 2*n; i++){
        int j = i;
        while(j+1 <= 2*n and a[j+1] < a[i]){
            j++;
        }
        vec.emplace_back(j-i+1);
        i = j;
    }

    for(int i = 0; i <= n; i++) dp[i] = 0;

    dp[0] = 1; //knapsack
    for(int wei : vec){
        for(int w = n; w >= wei; w--){
            dp[w] |= dp[w-wei];
        }
    }

    if(dp[n]) cout << "YES\n";
    else cout << "NO\n";

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