#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
int n,cnt[10010];
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    int mx = *max_element(cnt, cnt+10001);
    for(int i=1; i<=10000; i++)
        if(cnt[i] == mx)
            cout << i << " ";
}
