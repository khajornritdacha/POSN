#include <bits/stdc++.h>
using namespace std;

//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, Q; cin >> n >> Q;

    vector<vector<int>> nxt(1, vector<int>(26));
    vector<int> mx(1);

    for(int i = 1; i <= n; i++){
        string str; int w; cin >> str >> w;

        int node = 0; //start from root
        for(char c : str){
            if(nxt[node][c-'a'] == 0){
                nxt[node][c-'a'] = nxt.size();
                nxt.push_back(vector<int>(26));
                mx.push_back(0);
            }
            node = nxt[node][c-'a'];
            mx[node] = max(mx[node], w);
        }
    }

    while(Q--){
        string str; cin >> str;

        int node = 0; bool ok = true;
        for(char c : str){
            if(nxt[node][c-'a'] == 0){
                ok = false; break;
            }
            node = nxt[node][c-'a'];
        }

        if(ok){
            cout << mx[node] << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}

/*
3 5
ban 10
banana 12
banna 11
bad
band
ba
ban
bann -> should answer 11
*/