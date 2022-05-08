// Task: https://atcoder.jp/contests/dp/tasks/dp_z
// Algo: Convex Hull trick
// Date: 21/4/2022

#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
typedef long long ll;

int ptr, n;
ll H[N], C, dp[N];

struct Line{
    ll m, c;
    Line(ll m, ll c) {
        this->m = m;
        this->c = c;
    }
};
vector<Line> line;


ll cal(int idx, int x) {
    return line[idx].m*H[x] + line[idx].c;
}


ll chk(Line one, Line two, Line nl) {
    return (nl.c-one.c)*(two.m-nl.m) - (nl.c-two.c)*(one.m-nl.m);
}


ll getVal(int idx) {
    if (ptr >= line.size()) {
        ptr = int(line.size())-1;
    }
    while (ptr+1 < line.size() and cal(ptr, idx) >= cal(ptr+1, idx)) {
        ptr++;
    }

    return cal(ptr, idx)+H[idx]*H[idx]+C;
}


void addLine(Line newline) {
    while (line.size() >= 2 and chk(line.back(), line.end()[-2], newline) <= 0) {
        line.pop_back();
    }
    while (line.size() >= 1 and line.back().m == newline.m and line.back().c >= newline.c) {
        line.pop_back();
    }
    line.push_back(newline);
}

int main(void) {
    cin >> n >> C;
    for(int i = 1; i <= n; i++) {
        cin >> H[i];
    }

    for(int i = 1; i <= n; i++) {
        if (DEBUG) {
            cout << "Idx: " << i << "\n";
            for (Line cur : line) {
                cout << cur.m << " " << cur.c << "\n";
            }
        }
        
        if (i > 1) {
            dp[i] = getVal(i);
            // cout << "Idx " << i << ", ptr = " << ptr << "\n";
        }
        // cout << "---------------\n";

        addLine( Line(-2*H[i], dp[i]+H[i]*H[i]) );
    }
    cout << dp[n] << "\n";

    return 0;
}