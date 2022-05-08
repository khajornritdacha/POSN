#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

const int N = 2e5+10;
using tu = tuple<int,int,int>;
using ll = long long;
using pi = pair<int,int>;

int n,st[N],ed[N],idx[N],ans[N][2],fen[N];

void up(int idx, int val){
    if(idx <= 0) return;
    while(idx < N){
        fen[idx] += val;
        idx += idx&-idx;
    }
}

int sum(int idx){
    int res = 0;
    while(idx){
        res += fen[idx];
        idx -= idx&-idx;
    }
    return res;
}

int bi(int val, vector<int> &vec){
    int l = 0, r = (int)vec.size()-1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(vec[mid] == val) return mid;
        else if(val < vec[mid]) r = mid-1;
        else l = mid+1;
    }  
    return -1;
}

void solve(int cd){
    vector<int> val;
    map<int, int> mp;
    for(int i = 1; i <= n; i++){
        val.emplace_back(((cd) ? st[idx[i]] : ed[idx[i]]));
    }
    sort(val.begin(), val.end()); val.resize(unique(val.begin(), val.end())-val.begin());
    for(int i = 0; i < N; i++) fen[i] = 0;

    for(int i = 1; i <= n; i++){
        int tmp = ((cd) ? st[idx[i]] : ed[idx[i]]);
        int id = bi(tmp, val)+1;
        ans[idx[i]][cd] = sum(id);
        up(id, 1);
    }
    return;
}

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> st[i] >> ed[i];
        idx[i] = i;
    }

    sort(idx+1, idx+n+1, [&](const int &i, const int &j){ //inside
        if(ed[i] != ed[j]) return ed[i] > ed[j]; //sj <= si and ei <= ej -> si >= sj and ei <= ej
        return st[i] < st[j];
    }); //3 5, 2 5

    solve(1);

    sort(idx+1, idx+n+1, [&](const int &i, const int &j){ //contain
        if(st[i] != st[j]) return st[i] > st[j]; //si <= sj and ej <= ei -> si <= sj and ei >= ej
        return ed[i] < ed[j];
    });

    solve(0);

    for(int t : {0, 1}){
        for(int i = 1; i <= n; i++){
            cout << ans[i][t] << " ";
        }
        cout << "\n";
    }

    return 0;
}