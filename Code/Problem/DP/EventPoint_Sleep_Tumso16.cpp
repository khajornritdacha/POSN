#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

using ll = long long;
const int N = 1e5+10;

int n,ep[N];
bool no_wake;

///https://beta.programming.in.th/submissions/sMP1MrhTS0YOfU0UYss2

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int st,ed; cin >> st >> ed;
        ep[st]++, ep[ed]--;
    }

    int mx = -1, ans = 0;
    for(int i = 0; i <= 1e5; i++){
        if(i != 0) ep[i] += ep[i-1];
        if(ep[i] == n) no_wake = true;
        if(ep[i] > mx){ mx = ep[i], ans = i; }
    }

    if(no_wake) cout << "yes";
    else cout << "no";
    cout << " " << ans << "\n";
    return 0;
}
