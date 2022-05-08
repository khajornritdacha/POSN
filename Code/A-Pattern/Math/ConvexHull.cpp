// Algo: Convex Hull
// Task: https://open.kattis.com/problems/convexhull

#include <bits/stdc++.h>
using namespace std;

#define X real()
#define Y imag()

typedef long long ll;
typedef complex<long long> point;


ll cross(point a, point b) {
    return (conj(a)*b).Y;
}

vector<int> convex_hull(int n, const vector<point> &points) {
    // Find the bottom-most element (if there is a tie then choose the rightmost one)
    int ind = -1;
    for(int i = 0; i < n; i++) {
        if ((ind == -1) or 
            (points[i].Y < points[ind].Y) or 
            (points[i].Y == points[ind].Y and points[i].X > points[ind].X)) {
                ind = i;
            }
    }
    vector<int> cand, convex = {ind};
    for(int i = 0; i < n; i++) if (points[ind] != points[i]) cand.emplace_back(i);


    // Sort elements by polar angle
    sort(cand.begin(), cand.end(), [&](int a, int b) {
        point x = points[a]-points[ind], y = points[b] - points[ind];
        ll t = cross(x, y);
        return t != 0 ? t > 0 : norm(x) < norm(y);
    });
    // cout << "Candidates\n";
    // for(int i : cand) cout << points[i] << "\n";


    // Keep condition holds
    for(int c : cand) {
        while (convex.size() > 1) {
            point sle = points[convex.end()[-2]], le = points[convex.back()];
            if (cross(le-sle, points[c]-sle) <= 0) {
                convex.pop_back();
            } else {
                break;
            }
        }
        convex.push_back(c);
    }
    // cout << "Convex Hull\n";
    // for(int c : convex) cout << points[c] << "\n";

    return convex;
}   

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (true) {
        int n; cin >> n;
        if (n == 0) {
            break;
        }

        vector<point> points;
        for(int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            points.push_back(point(x, y));
        }

        vector<int> res = convex_hull(n, points);

        cout << res.size() << "\n";
        for(int r : res) cout << points[r].X << " " << points[r].Y << "\n";   
    }

    return 0;
}