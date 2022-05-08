#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
int n,K,ans;
multiset<pi> ss;
multiset<int> av;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        av.insert(x);
    }
    for(int t=1; ; t++){
        while(ss.size() > 0 and ss.begin()->first == t){
            av.insert(ss.begin()->second);
            ss.erase(ss.begin());
        }
        if(av.size() == 0)
            break;
        //cout << av.size() << "\n";
        ans++;
        if(K > 0){
            ss.insert({t+(*av.begin())+1, *av.begin()});
            K--;
        }
        av.erase(av.begin());
    }
    cout << ans << "\n";
}
