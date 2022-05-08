#include <bits/stdc++.h>
#define DEBUG 0
#define int long long
using namespace std;

const int N = 1e5+10;
using pi = pair<int,int>;
using ll = long long;
using lb = long double;

///Parallel B-search : find the least number of elements from the entire array that deleting them will satisfy i-th query.

///https://beta.programming.in.th/tasks/o59_mar_c1_atleast

int opera, times;

int n,Q,l[N],r[N],S[N],T[N],res[N];
ll qs[N];
lb U[N];
vector<pi> vec;
vector<int> event[N];

class fenwick{
    ll fen[N] = {};
public:

    void up(int idx, int val){
        while(idx <= n){
            fen[idx] += val;
            idx += idx&-idx;
        }
    }

    ll sum(int idx){
        ll res = 0;
        if(idx == 0) return 0;
        while(idx){
            res += fen[idx];
            idx -= idx&-idx;
        }
        return res;
    }

    void clear(){
        for(int i = 0; i <= n; i++) fen[i] = 0;
    }
};

fenwick val, cnt;

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    vec.resize(n+1);
    vec[0].first = -1e9;
    for(int i = 1; i <= n; i++){
        cin >> vec[i].first;
        vec[i].second = i;
        qs[i] = qs[i-1]+vec[i].first;
    }

    for(int i = 1; i <= Q; i++){
        cin >> S[i] >> T[i] >> U[i];
        res[i] = -1;
        l[i] = 0;
        r[i] = n;
    }

    sort(vec.begin(), vec.end());

    if(DEBUG){
        cout << "VECTOR\n";
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i].first << " " << vec[i].second << "\n";
        }
        cout << "\n";
    }

    bool con = true;
    while(con){
        times++;
        con = false;

        if(DEBUG){
            cout << "-------------------\n";
            cout << "CURRENT : " << times << "\n";
        }

        for(int i = 1; i <= Q; i++){
            if(DEBUG) cout << l[i] << " " << r[i] << "\n";
            if(l[i] <= r[i]){
                con =  true;
                int mid = (l[i]+r[i])>>1;
                assert(0 <= mid and mid <= n);
                event[mid].emplace_back(i);
            }
        }

        if(DEBUG and false){
            for(int i = 0; i <= n; i++){
                if(event[i].size() == 0) continue;
                cout << "I " << i << " : ";
                for(int idx : event[i])
                    cout << idx << " ";
                cout << "\n";
            }
        }

        for(int i = 0; i <= n; i++){

            if(i != 0){
                cnt.up(vec[i].second, 1);
                val.up(vec[i].second, vec[i].first);
            }

            for(int idx : event[i]){
                opera++;
                ll tot = qs[T[idx]] - qs[S[idx]-1] - (val.sum(T[idx]) - val.sum(S[idx]-1));
                ll cou = (T[idx] - S[idx] + 1) - (cnt.sum(T[idx]) - cnt.sum(S[idx]-1));

                if(DEBUG){
                    cout << "I " << i << ", " << idx << " = " << tot << " " << cou << " " << U[idx] << "\n";
                    cout << cnt.sum(T[idx]) << " " << cnt.sum(S[idx]-1) << "\n";
                }

                if(cou != 0 and (lb)tot/cou >= U[idx]){
                    r[idx] = i-1;
                    res[idx] = T[idx]-S[idx]+1-cou;
                }else{
                    l[idx] = i+1;
                }
            }

            event[i].clear();
        }

        if(DEBUG){
            cout << "-------------------\n";
        }

        cnt.clear();
        val.clear();
    }

    for(int i = 1; i <= Q; i++){
        cout << res[i] << "\n";
    }


    if(DEBUG){
        cout << "TOTAL B search : " << times << "\n";
        cout << "TOTAL Operation : " << opera << "\n";
    }

    return 0;
}
