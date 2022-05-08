#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;

///https://codeforces.com/problemset/problem/1437/D
/// 6 Nov 2021

int n,a[N],num[N];

void test_case(){
    memset(num, 0, sizeof(num));

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    num[0] = 1;
    int lv = 1;
    for(int i = 2, cur = 1; i <= n; i++){
        if(a[i] < a[i-1]){
            cur++;
            if(cur > num[lv-1]){
                lv++;
                cur = 1;
            }
        }
        num[lv]++;
    }
    if(n == 1) cout << "0\n";
    else cout << lv << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
