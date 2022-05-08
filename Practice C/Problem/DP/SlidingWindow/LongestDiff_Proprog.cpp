#include<bits/stdc++.h>
using namespace std;
map<int,int> chk;
int t,n;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        int mx=0;
        cin >> n;
        deque<int> dq;
        for(int i=1; i<=n; i++){
            int x;
            cin >> x;
            while(chk[x]){
                chk[dq.front()]--;
                dq.pop_front();
            }
            if(!chk[x]){
                chk[x]=true;
                dq.emplace_back(x);
            }
            mx = max(mx, (int)dq.size());
        }
        cout << mx << "\n";
        chk.clear();
    }
}
