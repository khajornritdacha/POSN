#include <bits/stdc++.h>
using namespace std;


int main(void){
    int n;
    cin >> n;
    if(n == 1){ cout << 1; return 0; }
    if(n <= 3){ cout << "NO SOLUTION\n"; return 0;}
    for(int i = 1, now = 2; i <= n; i++, now += 2){
        if(now > n) now = 1;
        cout << now << " ";
    }
    return 0;
}
