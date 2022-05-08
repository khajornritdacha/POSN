#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int ans=2e9,n,m,x[15],y[15],z[15],a[15],b[15],c[15];
void dfs(int u=0,int bit=1,int na=0,int nb=0,int nc=0,int dis=0){
    if(na>=n&&nb>=n&&nc>=n){
        ans=min(ans,dis);
        return;
    }
    vector<bool> bo(m+1,false);
    int cnt=0,temp=bit;
    while(temp){
        bo[cnt++]=temp%2;
        temp = temp>>1;
    }
    for(int i=1;i<=m;i++){
        if(!bo[i])
            dfs(i,bit+(1<<i),na+a[i],nb+b[i],nc+c[i],dis+(x[i]-x[u])*(x[i]-x[u])+(y[i]-y[u])*(y[i]-y[u])+(z[i]-z[u])*(z[i]-z[u]));
    }
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x[0] >> y[0] >> z[0] >> m;
    for(int i=1;i<=m;i++){
        cin >> x[i] >> y[i] >> z[i] >> a[i] >> b[i] >> c[i];
    }
    dfs();
    cout << ans;
}
