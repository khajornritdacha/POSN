#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e4+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
int n,b[N],p[N],L,P;

int solve(){
    vector<pi> vec;
    priority_queue<int> pq;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> b[i] >> p[i];
    }
    cin >> L >> P;
    if(P >= L)
        return 0;
    vec.emplace_back(-2e9, -2e9);
    for(int i=1; i<=n; i++){
        vec.emplace_back(L-b[i], p[i]);
    }
    vec.emplace_back(2e9, 2e9);
    sort(vec.begin(), vec.end());
    int ter = 0, j=1, cnt=0;
    while(true){
        int i = upper_bound(vec.begin(), vec.end(), pi(P+ter, 1e9))-vec.begin();
        //cout << "I : " << i << "\n";
        if(i <= 1)
            return -1;
        i--;
        while(j <= i){
            pq.emplace(vec[j++].second);
        }
        if(pq.empty())
            return -1;
        ter += pq.top();
        pq.pop();
        ++cnt;
        if(P+ter >= L){
            return cnt;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int res = solve();
        cout << res << "\n";
    }
}
