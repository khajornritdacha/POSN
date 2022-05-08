#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

const int N = 2e5+10;
using tu = tuple<int,int,int>;
using pi = pair<int,int>;
using ll = long long;

int n,K,st[N],ed[N],ans,idx[N];

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        cin >> st[i] >> ed[i];
        idx[i] = i;
    }

    sort(idx+1, idx+n+1, [&](const int &i, const int &j){
            if(ed[i] != ed[j]) return ed[i] < ed[j];
            return st[i] < st[j];
    });

    multiset<int> ss;
    for(int i = 1; i <= K; i++) ss.insert(0);

    for(int i = 1; i <= n; i++){
        auto it = ss.upper_bound(st[idx[i]]); //find the maximum end time that is not greater than i-th start time
        if(it != ss.begin()){
            it--;
            ss.erase(it);
            ss.insert(ed[idx[i]]);
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}