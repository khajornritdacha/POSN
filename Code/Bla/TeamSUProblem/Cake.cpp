#include<bits/stdc++.h>
using namespace std;
int n,a,pre,ans;
bitset<100010> chk;
deque<int> dq;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a;
        if(a<pre){
            while(!dq.empty()&&a<dq.back()){
                chk[dq.back()]=false;
                dq.pop_back();
            }
        }
        if(!chk[a]){
            chk[a]=true;
            ans++;
            dq.emplace_back(a);
        }
        pre=a;
    }
    cout << ans;
}
