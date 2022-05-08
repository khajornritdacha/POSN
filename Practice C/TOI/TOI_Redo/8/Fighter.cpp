#include <bits/stdc++.h>
using namespace std;

const int N = 2e4+10, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int n,H[2],cnt[2];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    H[0] = H[1] = n;
    for(int i = 1, pre = 0; i <= 2*n; i++){
        int x; cin >> x;
        int at = x&1;

        if(at != pre) cnt[pre] = 0;

        if(++cnt[at] >= 3){
            H[!at] -= 3;
        } else {
            H[!at] -= 1;
        }

        if(H[!at] <= 0){
            cout << at << "\n";
            cout << x << "\n";
            return 0;
        }

        pre = at;        
    }
    return 0;
}