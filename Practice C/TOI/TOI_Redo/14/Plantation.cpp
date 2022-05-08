#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using lb = double;

struct P{
    lb x,y;
};

bool cmpx(const P &A, const P &B){
    if(A.x != B.x) return A.x < B.x;
    return A.y < B.y;
}

bool cmpy(const P &A, const P &B){
    if(A.y != B.y) return A.y < B.y;
    return A.x < B.x;
}

int n;
lb R,D;
P a[N],tmp[N];

lb dis(P A, P B){
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

lb solve(int l, int r){
    if(l == r) return 1e9;
    int mid = (l+r)>>1;
    lb ml = solve(l, mid), mr = solve(mid+1, r);
    lb md = min(ml, mr), mn = md;

    int k = 0;
    for(int i = l ; i <= r; i++){
        if(abs(a[i].x - a[mid].x) < md){
            tmp[k++] = a[i];
        }
    }

    sort(tmp, tmp+k, cmpy);

    for(int i = 0; i < k; i++){
        for(int j = i+1, cnt = 0; j < k and tmp[j].y-tmp[i].y < md and cnt < 10; j++, cnt++){
            mn = min(mn, dis(tmp[i], tmp[j]));
        }
    }
    //cout << l << " " << r << " " << mn << "\n";
    //for(int i = 0; i < k; i++) cout << tmp[i].x << " " << tmp[i].y << "\n";
    return mn;
}

void test_case(){
    cin >> n >> R >> D;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
    }

    sort(a+1, a+n+1, cmpx);

    lb mn = solve(1, n);
    //cout << setprecision(3) << fixed << mn << "\n";

    if(mn-2*R >= D) cout << "Y\n";
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