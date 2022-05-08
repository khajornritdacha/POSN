#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 60;

//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/kth-min-xor-37903b94/

class trie{
    vector<vector<int>> nxt;
    vector<int> sum;
    
    public:
        trie(){
            nxt.resize(1, vector<int>(2)); //bit 0, 1
            sum.resize(1);
        }

        void add(ll num){
            int node = 0;
            for(int i = N; i >= 0; i--){
                int cur = ((num&(1ll<<i)) != 0); //must be 1ll
                if(nxt[node][cur] == 0){
                    nxt[node][cur] = nxt.size();
                    nxt.push_back(vector<int>(2));
                    sum.push_back(0);
                }
                node = nxt[node][cur];
                sum[node]++;
            }
            return;
        }

        ll ask(ll num, ll want){
            int node = 0;
            ll res = 0;
            for(int i = N; i >= 0; i--){
                int cur = ((num&(1ll<<i)) != 0);
                if(nxt[node][cur] == 0){
                    node = nxt[node][!cur];   
                    res |= 1ll<<i; //must be 1ll
                } else if(nxt[node][!cur] == 0){
                    node = nxt[node][cur];
                } else if(sum[nxt[node][cur]] >= want){
                    node = nxt[node][cur];                   
                } else {
                    want -= sum[nxt[node][cur]];
                    node = nxt[node][!cur];
                    res |= 1ll<<i;
                }
            }

            return res;
        }

};

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int Q; cin >> Q;
    trie tr;
    while(Q--){
        int op; cin >> op;
        if(op == 1){
            ll x; cin >> x;
            tr.add(x);
        } else {
            ll x, K; cin >> x >> K;
            cout << tr.ask(x, K) << "\n";
        }
    }
    return 0;
}