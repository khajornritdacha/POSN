#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using lb = long double;

struct P{
    lb x,y;
    bool operator < (const P &other) const{
        if(x != other.x) return x < other.x;
        return y < other.y;
    }
};

int n;
lb R,D;
P a[N];

lb dis(P A, P B){
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

void test_case(){
    cin >> n >> R >> D;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
    }
    sort(a+1, a+n+1);
    bool ok = true;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= min(n, i+10); j++){
            if(i == j) continue;
            if(dis(a[i], a[j]) - 2*R < D){
                ok = false;
                break;
            }
        }
        if(!ok) break;
    }
    if(ok) cout << "Y\n";
    else cout << "N\n";
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}