#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
const int N = 2e4+10;

using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

vector<pi> num;
vector<tu> qq[4];
int n,Q,fen[N],a[N],ans[N*10];
///https://beta.programming.in.th/tasks/codecube_021
/// num; S <= val <= E, A <= idx <= B  -----> num(val<=E, idx<=B) - num(val<S, idx<=B) - num(val<=E, idx<A) + num(val<S, idx<A)

void up(int idx, int val){
    while(idx <= n){
        fen[idx] += val;
        idx += idx&-idx;
    }
}

int sum(int idx){
    if(idx <= 0) return 0;
    int res = 0;
    while(idx){
        res += fen[idx];
        idx -= idx&-idx;
    }
    return res;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        num.emplace_back(a[i], i);
    }
    sort(num.begin(), num.end());

    for(int i=1; i<=Q; i++){
        int A,B,S,E;
        cin >> A >> B >> S >> E;
        qq[0].emplace_back(E, B, i);
        qq[1].emplace_back(S-1, B, i);
        qq[2].emplace_back(E, A-1, i);
        qq[3].emplace_back(S-1, A-1, i);
        //cout << "I : " << i << " = " << ans[i] << "\n";
    }

    for(int t=0, j=0; t<4; t++, j=0){
        sort(qq[t].begin(), qq[t].end());
        //cout << "-----------------------\nT : " << t << "\n";
        for(int i=0; i<Q; i++){
            auto [val, idx, apos] = qq[t][i];
            while(j < n and num[j].first <= val){
                up(num[j].second, 1);
                j++;
            }
            //cout << "IDX : " << idx << " " << j << "\n";
            ans[apos] += sum(idx)*(t == 1 or t == 2 ? -1 : 1);
        }
        memset(fen, 0, sizeof(fen));
    }

    for(int i=1; i<=Q; i++){
        cout << ans[i] << " \n"[i==Q];
    }
}
