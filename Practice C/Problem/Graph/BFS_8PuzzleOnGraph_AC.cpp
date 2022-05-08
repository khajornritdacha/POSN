#include <bits/stdc++.h>
using namespace std;

const int N = 15;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

///https://atcoder.jp/contests/abc224/tasks/abc224_d

map<array<int, 9>, int> dis;
int m;
bool G[N][N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    array<int, 9> st;
    cin >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        G[u][v] = G[v][u] = true;
    }
    for(int i = 0; i < 9; i++) st[i] = -1;
    for(int i = 0; i < 8; i++){
        int pos; cin >> pos;
        pos--;
        st[pos] = i;
    }
    queue<array<int, 9>> qq;
    qq.emplace(st);
    dis[st] = 0;
    while(!qq.empty()){
        array<int, 9> now = qq.front(); qq.pop();
        int blank = -1, res = 0;
        for(int i = 0; i < 8; i++){
            res += (now[i] == i);
        }
        for(int i = 0; i < 9; i++){
            if(now[i] == -1){
                blank = i;
            }
            //cout << now[i] << " ";
        }
        //cout << "\n";
        if(res == 8){
            cout << dis[now] << "\n";
            return 0;
        }

        //assert(blank >= 0);
        int cur_dis = dis[now];
        for(int i = 0; i < 9; i++){
            if(i == blank or !G[i][blank]) continue;
            swap(now[i], now[blank]);
            if(dis.count(now) == 0){
                dis[now] = cur_dis+1;
                    qq.emplace(now);
            }
            swap(now[i], now[blank]);
        }
    }
    cout << "-1\n";
    return 0;
}
