#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

const int N = 2e5+10;
using tu = tuple<int,int,int>;
using ll = long long;
using pi = pair<int,int>;

int n,st[N],ed[N],idx[N],ans[N][2];

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> st[i] >> ed[i];
        idx[i] = i;
    }

    //check if current contains some ranges
    //sa <= sb and eb <= ea
    //3 5, 2 5
    sort(idx+1, idx+n+1, [&](const int &i, const int &j){
        if(ed[i] != ed[j]) return ed[i] < ed[j];
        return st[i] > st[j]; 
    });

    set<int> ss;
    for(int i = 1; i <= n; i++){
        auto it = ss.lower_bound(st[idx[i]]);
        if(it != ss.end()){ //there is some start point greater than the current one
            ans[idx[i]][0] = 1;
        }
        ss.insert(st[idx[i]]);
    }

    //check if current is inside some ranges
    //sb <= sa and ea <= eb
    //3 5, 4 5
    sort(idx+1, idx+n+1, [&](const int &i, const int &j){
        if(ed[i] != ed[j]) return ed[i] > ed[j];
        return st[i] < st[j];
    });

    ss.clear();
    for(int i = 1; i <= n; i++){
        auto it = ss.upper_bound(st[idx[i]]);
        if(it != ss.begin()){
            ans[idx[i]][1] = 1;
        }
        ss.insert(st[idx[i]]);
    }

    for(int t : {0, 1}){
        for(int i = 1; i <= n; i++){
            cout << ans[i][t] << " ";
        }
        cout << "\n";
    }

    return 0;
}