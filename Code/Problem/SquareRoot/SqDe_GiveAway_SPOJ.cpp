#include <bits/stdc++.h>
using namespace std;

//https://www.spoj.com/problems/GIVEAWAY/

const int N = 5e5+10, NB = 10010;

int Q, n, arr[N], B;
vector<int> ord[NB];

void up(int a, int b){
    int bid = a/B;

    // cout << "BEFORE : ";
    // for(int v : ord[bid]) cout << v << " ";
    // cout << "\n";

    for(int i = 0; i < ord[bid].size(); i++){
        if(ord[bid][i] == arr[a]){
            ord[bid].erase(ord[bid].begin()+i);
            break;
        }
    }

    arr[a] = b;
    if(ord[bid].empty() or arr[a] <= ord[bid][0]){
        ord[bid].insert(ord[bid].begin(), arr[a]);
    } else {
        for(int i = (int)ord[bid].size()-1; i >= 0; i--){
            if(arr[a] >= ord[bid][i]){
                ord[bid].insert(ord[bid].begin()+i+1, arr[a]);
                break;
            }
        }
    }

    // cout << "AFTER : ";
    // for(int v : ord[bid]) cout << v << " ";
    // cout << "\n";
}

int bs(int id, int val){
    int l = 0, r = int(ord[id].size())-1, res = ord[id].size();
    while(l <= r){
        int mid = (l+r)>>1;
        if(ord[id][mid] >= val){
            res = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    res = int(ord[id].size()) - res;
    return res;
}

int ask(int a, int b, int c){
    int res = 0;
    if(a/B == b/B){
        for(int i = a; i <= b; i++) res += (arr[i] >= c);
        return res;
    }

    int aid = a/B, bid = b/B;
    for(int i = a, lim = (aid+1)*B-1; i <= lim; i++){
        res += (arr[i] >= c);
    }
    for(int i = aid+1; i <= bid-1; i++){
        res += bs(i, c);
    }
    for(int i = bid*B; i <= b; i++){
        res += (arr[i] >= c);
    }

    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    B = 1+sqrt(10.0*n);
    // cout << "BS : " << B << "\n";
    for(int b = 0; b*B <= n; b++){
        for(int i = b*B, lim = (b+1)*B-1; i <= lim and i <= n; i++){
            if(i == 0) continue;

            ord[b].emplace_back(arr[i]);
        }
        sort(ord[b].begin(), ord[b].end());
    }

    cin >> Q;
    while(Q--){
        int cd; cin >> cd;
        int a, b; cin >> a >> b;
        if(cd == 0){
            int c; cin >> c;
            cout << ask(a, b, c) << "\n"; 
        } else if(cd == 1){
            up(a, b);
        }
    }

    return 0;
}