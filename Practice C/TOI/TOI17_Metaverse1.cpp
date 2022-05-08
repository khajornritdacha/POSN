#include <bits/stdc++.h>
using namespace std;


const int MXP = 20, MXK = 2e4+10, INF = 1e9+10;

int M, N, K, P;
int dp[MXP][MXK];


struct Point {
    int w_r, w_c, o_r, o_c; // Attrubute -> position of warp point
    Point(int a, int b, int c, int d) { // Constructor
        w_r = a, w_c = b, o_r = c, o_c = d;
    }
};
vector<Point> points;


int dis(int, int);
void solve();
void get_ans(int &, int &);


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> M >> N >> K >> P;
    points.push_back(Point(-1, -1, 1, 1));
    for (int i = 1; i <= K; i++) {
        int w_r, w_c, o_r, o_c;
        cin >> w_r >> w_c >> o_r >> o_c;
        points.push_back(Point(w_r, w_c, o_r, o_c));
    }
    points.push_back(Point(M, N, -1, -1));

    int mn_dis = M+N-2;
    int mn_ticket = 0;

    solve();
    get_ans(mn_dis, mn_ticket);
    
    cout << mn_dis << " " << mn_ticket << "\n";

    return 0;
}



int dis(int a, int b) {
    return abs(points[a].o_r-points[b].w_r) + abs(points[a].o_c-points[b].w_c);
}


void solve() {    
    for (int i = 1; i <= K; i++) dp[1][i] = dis(0, i);

    for (int t = 2; t <= P; t++){
        for (int i = 1; i <= K; i++) {
            dp[t][i] = INF; // INF = 1e9+10
            for(int j = 1; j <= K; j++) {
                dp[t][i] = min(dp[t][i], dp[t-1][j] + dis(j, i));
            }
        }
    }
}


void get_ans(int &mn_dis, int &mn_ticket) {
    for (int t = 1; t <= P; t++) {
        for (int i = 1; i <= K; i++) {
            int cur_cost = dp[t][i] + dis(i, K+1);
            if (cur_cost < mn_dis) {
                mn_dis = cur_cost;
                mn_ticket = t;
            }
        }
    }
}
