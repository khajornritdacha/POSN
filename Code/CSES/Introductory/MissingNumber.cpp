#include <bits/stdc++.h>
using namespace std;


int main(void){
    int n;
    cin >> n;
    vector<bool> miss(n+1, 1);
    for(int i = 1; i < n; i++){
        int x; cin >> x;
        miss[x] = false;
    }
    for(int i = 1; i <= n; i++){
        if(miss[i]){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
