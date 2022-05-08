#include<bits/stdc++.h>
using namespace std;
const int N = 2e4+10;
struct ST{
    char name[35];
    int score;
};
ST st[N];
int n,T,mx;
main(){
    cin >> n >> T;
    for(int i=1; i<=n; i++){
        ST tmp;
        int mn = 1e9;
        cin >> tmp.name;
        tmp.score = 0;
        for(int j=1; j<=T; j++){
            int x;
            cin >> x;
            tmp.score+=x;
            mn = min(mn, x);
        }
        tmp.score-=mn;
        st[i] = tmp;
        mx = max(mx, tmp.score);
    }
    cout << mx << "\n";
    for(int i=1; i<=n; i++){
        if(st[i].score == mx){
            cout << st[i].name << "\n";
        }
    }
}
