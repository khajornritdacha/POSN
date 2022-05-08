#include <bits/stdc++.h>
using namespace std;

const int N = 55;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 20;
    while(t--){
        int m, n; cin >> m >> n;
        int res = 0;

        if((m-2*n)%2 == 0){
            int C = (m-2*n)/2;
            int AB = n-C;
            //cout << C << " " << AB << "\n";
            if(C >= 0 and AB >= 0){
                res = AB+1;
            }
        }

        cout << res << "\n";
    }

    return 0;   
}