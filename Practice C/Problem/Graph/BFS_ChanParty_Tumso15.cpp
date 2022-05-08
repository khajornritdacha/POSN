#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,a[N][N];
bool vi[N][N];
ll mx,now,Want;
priority_queue<tu, vector<tu>, greater<tu>> pend;
queue<pi> qq;
pi st;

///Actually, BFS using dijkstra is much easier:C
///https://beta.programming.in.th/tasks/tumso15_chanparty

void bfs(){
    while(!qq.empty()){
        auto [nr, nc] = qq.front(); qq.pop();
        vi[nr][nc] = true;
        if(a[nr][nc] > mx){
            pend.emplace(a[nr][nc], nr, nc);
            continue;
        }
        now += a[nr][nc];
        for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}){
            if(abs(dr-dc) != 1) continue;
            int gr = nr+dr, gc = nc+dc;
            if(gr < 1 or gr > n or gc < 1 or gc > n) continue;
            if(vi[gr][gc]) continue;
            vi[gr][gc] = true;
            qq.emplace(gr, gc);
        }
    }
}

void test_case(){
    mx = now = 0;
    cin >> n >> Want;
    cin >> st.first >> st.second;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    pend.emplace(a[st.first][st.second], st.first, st.second);
    while(true){
        if(now >= Want) break;
        auto [val,  r, c] = pend.top(); pend.pop();
        mx = val;
        qq.emplace(r, c);
        while(!pend.empty() and get<0>(pend.top()) <= mx){
            tie(val, r, c) = pend.top(); pend.pop();
            qq.emplace(r, c);
        }
        bfs();
    }
    cout << mx << "\n";
    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) vi[i][j] = 0;
    while(!pend.empty()) pend.pop();
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
