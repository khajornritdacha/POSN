#include <bits/stdc++.h>
using namespace std;

///https://www.spoj.com/problems/ADAFIELD/

void test_case(){
    int n,m,Q;
    priority_queue<int> pq[2];
    set<int> point[2];
    map<int, int> pend[2];
    cin >> n >> m >> Q;
    pq[0].emplace(n), pq[1].emplace(m);
    point[0] = {0, n};
    point[1] = {0, m};
    while(Q--){
        int code, x;
        cin >> code >> x;
        if(point[code].count(x) == 0){
            point[code].insert(x);
            int l = *(--point[code].lower_bound(x)), r = *point[code].upper_bound(x);
            pq[code].emplace(x-l);
            pq[code].emplace(r-x);
            pend[code][r-l]++;
            while(!pq[code].empty() and pend[code][pq[code].top()]){
                pend[code][pq[code].top()]--; pq[code].pop();
            }
        }
        cout << 1ll*pq[0].top()*pq[1].top() << "\n";
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
