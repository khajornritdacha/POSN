#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
double mn=2e9;
int n,m,pr[]={-1,-1,-1,0,0,1,1,1},pc[]={-1,0,1,-1,1,-1,0,1};
void solve(vector<vector<double>> vec,int lv,double val){
    if(lv==m*n){ if(val<mn) mn=val; return;}
    vector<vector<double>> x=vec;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vec[i][j]==0) continue;
            for(int o=0;o<8;o++){
                int nr=i+pr[o],nc=j+pc[o];
                if(nr<1||nc<1||nr>n||nc>m) continue;
                if(vec[nr][nc]==0) continue;
                vec[nr][nc]+=(vec[i][j]/10);
            }
            vec[i][j]=0;
            solve(vec,lv+1,val+x[i][j]);
            vec=x;
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << setprecision(2) << fixed;
    cin >> n >> m;
    vector<vector<double>> a;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        a[i].resize(m+1);
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    solve(a,0,0);
    cout << mn;
}
