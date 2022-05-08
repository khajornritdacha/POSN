#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using pi = pair<int,int>;
int n,Q,a[N];
deque<pi> dq;
map<int,int> ans;
vector<int> vec;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    a[n+1] = 0;
    dq.emplace_back(a[1], 0);
    for(int i=2; i<=n+1; i++){
        while(!dq.empty() and dq.back().first >= a[i]){
            ans[dq.back().second]++;
            dq.pop_back();
        }
        if(dq.empty())
            dq.emplace_back(a[i], 0);
        else
            dq.emplace_back(a[i], max(a[i]-dq.back().first, dq.back().second));
    }

    auto it = ans.begin();
    vec.emplace_back(it->first);
    it++;
    for(auto it2 = ans.begin(); it!=ans.end(); it++, it2++){
        (it->second) += (it2->second);
        vec.emplace_back(it->first);
    }

    while(Q--){
        int x; cin >> x;
        cout << n-ans[vec[(upper_bound(vec.begin(), vec.end(), x)-vec.begin())-1]] << "\n";
    }

    return 0;
}
