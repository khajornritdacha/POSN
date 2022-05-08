#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using ll = long long;

ll a,b;

void test_case(){
    cin >> a >> b;
    if((a+b)%3 == 0 and min(a,b)*2 >= max(a,b)){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
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
