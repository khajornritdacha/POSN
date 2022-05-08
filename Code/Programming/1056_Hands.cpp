#include<bits/stdc++.h>
using namespace std;
int n,K,ans;
priority_queue<int> pq;
main(){
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        pq.emplace(x);
    }
    while(!pq.empty()){
        for(int i=0; i<K and !pq.empty(); i++){
            if(i == 0)
                ans+=pq.top();
            pq.pop();
        }
    }
    cout << ans << "\n";
}
