#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1627/D

const int N = 1e6+5;

int n;
bool in[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        in[x] = true;
    }

    int cnt = 0;
    for(int i = 1; i < N; i++){
        int g = 0;
        for(int j = i; j < N; j += i){
            if(in[j]){
                g = __gcd(g, j);
            }
        }
        cnt += (g == i);
    }
    
    cout << cnt-n << "\n";

    return 0;
}