#include<bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;
int a[5][5],n,m,st,nv,nh,cnt,al='A';
vector<int> but[10], ans;
void press(int r, int c, int t){
    if(r == 1 and c == 1){
        for(int i=0; i<t and !ans.empty(); i++)
            ans.pop_back();
        return;
    }
    if(t == 0) return;
    int now = a[r][c];
    ans.emplace_back(but[now][(t-1+sz(but[now]))%sz(but[now])]);
}
main(){
    cin >> n >> st >> m;
    for(int i=1; i<=3; i++) for(int j=1; j<=3; j++){
        a[i][j] = ++cnt;
        if(cnt >= 2){
            for(int k=0; k<3+(cnt == 7 or cnt == 9); k++, al++){
                but[cnt].emplace_back(al);
            }
        }
    }
    for(int i=1; i<=3; i++) for(int j=1; j<=3; j++){
        if(a[i][j] == st){
            nv = i, nh = j;
            press(i, j, m);
            break;
        }
    }
    for(int i=1; i<n; i++){
        int h,v,t;
        cin >> h >> v >> t;
        nh+=h, nv+=v;
        press(nv, nh, t);
    }
    for(int an : ans)
        cout << (char)an;
    if(sz(ans) == 0)
        cout << "null";
}
