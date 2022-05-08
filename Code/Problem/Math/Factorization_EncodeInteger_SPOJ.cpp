#include <bits/stdc++.h>
using namespace std;

///https://vjudge.net/contest/463025#problem/B

void test_case(){
    int n,tmp,cnt[15] = {};
    cin >> n;
    if(n == 0){ cout << "10\n"; return; }
    if(n == 1){ cout << "1\n"; return; }

    tmp = n;
    for(int i = 9; i >= 2; i--){
        while(tmp % i == 0){
            tmp /= i;
            cnt[i]++;
        }
    }
    if(tmp != 1){ cout << "-1\n"; return; }

    for(int i = 2; i <= 9; i++){
        while(cnt[i]){
            cout << i;
            cnt[i]--;
        }
    }
    cout << "\n";
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
