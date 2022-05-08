#include<bits/stdc++.h>
using namespace std;

const int N = 5e3+10;
int H,L,n,cnt[N];

main(){
    int mx = 0;
    cin >> H >> L >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(int i=L; i<=L+H; i++){
        mx = max(mx, cnt[i]);
    }
    cout << mx;
}
