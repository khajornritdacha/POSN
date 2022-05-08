#include <bits/stdc++.h>
using namespace std;


int n,m,C[15];
vector<int> in[15];
set<vector<int>> ban;

//https://codeforces.com/problemset/problem/1574/D
//Greedy by choosing last elements of every slot if it is banned then just tried to swap any slot with its previous

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> C[i];
        in[i].resize(C[i]+1);
        for(int j = 1; j <= C[i]; j++){
            cin >> in[i][j];
        }
    }

    cin >> m;
    for(int j = 1; j <= m; j++){
        vector<int> vec(n);
        for(int &v : vec) cin >> v;
        ban.insert(vec);
    }

    vector<int> chk;
    for(int i = 1; i <= n; i++) chk.emplace_back(C[i]);
    if(ban.count(chk) == 0){
        for(int cc : chk) cout << cc << " ";
        return 0;
    }

    int mx = 0;
    vector<int> ans;
    for(auto it = ban.begin(); it != ban.end(); it++){
        chk = *it;
        for(int i = 0; i < n; i++){
            if(chk[i] > 1){
                chk[i]--;
                if(ban.count(chk) == 0){
                    int sum = 0;
                    for(int j = 0; j < n; j++){
                        sum += in[j+1][chk[j]];
                    }
                    if(sum > mx){
                        mx = sum;
                        ans = chk;
                    }

                }
                chk[i]++;
            }
        }
    }

    for(int an : ans) cout << an << " ";

    return 0;
}