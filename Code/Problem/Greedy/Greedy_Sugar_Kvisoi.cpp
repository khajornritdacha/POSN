#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

const int N = 1e5+10, INF = 1e9;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,a[N];

void test_case(){
    cin >> n;
    int l = -1, r = -1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 1){
            if(l == -1) 
                l = i;
            r = i;
        }
    }

    if(l == -1){
        cout << "0\n";
        return;
    }

    int ans = 0;
    for(int i = l; i <= r; i++){
        if(a[i] == 0) ans++;
    }

    cout << ans << "\n";
    return;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
