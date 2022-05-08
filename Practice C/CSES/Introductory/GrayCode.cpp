#include <bits/stdc++.h>
using namespace std;

const int N = 1<<17;
using ll = long long;

int n;
bool now[N];

void solve(int lv){
    if(lv <= 0) return;
    if(lv == 1){
        for(int i = n; i >= 1; i--){
            cout << now[i];
        }
        cout << "\n";
    }
    solve(lv-1);
    now[lv] = !now[lv];
    if(lv == 1){
        for(int i = n; i >= 1; i--){
            cout << now[i];
        }
        cout << "\n";
    }
    solve(lv-1);
}

int main(void){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    solve(n);
    return 0;
}
