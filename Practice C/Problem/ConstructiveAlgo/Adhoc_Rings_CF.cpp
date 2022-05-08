#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/contest/1562/problem/C

const int N = 2e4+10;

int n;
char str[N];

void test_case(){
    int zero = 0;
    
    cin >> n >> str+1;
    
    for(int i = 1; i <= (n+1)/2; i++){
        if(str[i] == '0'){
            zero = i;
            break;
        }
    }
    if(zero != 0){
        cout << zero << " " << n << " " << zero+1 << " " << n << "\n";
        return;
    }

    for(int i = (n+1)/2+1; i <= n; i++){
        if(str[i] == '0'){
            zero = i;
            break;
        }
    }
    if(zero != 0){
        cout << 1 << " " << zero << " " << 1 << " " << zero-1 << "\n";
        return;
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += (str[i] == '1');
    assert(cnt == n);

    cout << 1 << " " << n-1 << " " << 2 << " " << n << "\n";

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