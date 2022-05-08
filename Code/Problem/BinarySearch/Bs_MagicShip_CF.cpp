#include<bits/stdc++.h>
#define DEBUG true
#define int long long
using namespace std;

const int N = 1e5+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
using lb = long double;
///https://codeforces.com/problemset/problem/1117/C
int x1,y1,x2,y2,n,qs[N][2][2];
pi toi[300];
char str[N];

bool chk(int K){
    int x3 = (qs[n][1][0]*(K/n)+qs[K%n][1][0])-(qs[n][1][1]*(K/n)+qs[K%n][1][1])+x1;
    int y3 = (qs[n][0][0]*(K/n)+qs[K%n][0][0])-(qs[n][0][1]*(K/n)+qs[K%n][0][1])+y1;
    //cout << K << " " << x3 << " " << y3 << "\n";
    return (abs(x3-x2)+abs(y3-y2) <= K);
}

void test_case(){
    cin >> x1 >> y1 >> x2 >> y2 >> n >> str+1;
    toi['U'] = pi(0, 0), toi['D'] = pi(0, 1), toi['R'] = pi(1, 0), toi['L'] = pi(1, 1);
    for(int i=1; i<=n; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                qs[i][j][k] += qs[i-1][j][k];
            }
        }
        pi tmp = toi[str[i]];
        qs[i][tmp.first][tmp.second]++;
    }
    int l = 1, r = 1e18, mid, ans = -1;
    while(l <= r){
        mid = l+(r-l)/2;
        if(chk(mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
   // cin >> t;
    while(t--){
        test_case();
    }
}
