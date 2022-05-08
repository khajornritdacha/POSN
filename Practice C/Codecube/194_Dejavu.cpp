#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,a[N],ans[N];
priority_queue<pair<int,int>> pq[N];
vector<int> vec;
long long sum;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        int k = upper_bound(vec.begin(), vec.end(), a[i])-vec.begin();
        if(k == vec.size())
            vec.emplace_back(a[i]);
        else
            vec[k] = a[i];
        ans[i] = k+1;
        pq[ans[i]].emplace(a[i], i);
    }

    /*for(int i=1; i<=n; i++){
        cout << ans[i] << " \n"[i==n];
    }*/

    int idx = n, last = 1e9;
    for(int k=vec.size(); k>=1; k--){
        while(!pq[k].empty() and (pq[k].top().second > idx or pq[k].top().first > last))
            pq[k].pop();
        if(!pq[k].empty()){
            sum += pq[k].top().first;
            idx = pq[k].top().second;
            last = pq[k].top().first;
        }
    }
    cout << vec.size() << " " << sum;
}
