#include<bits/stdc++.h>
using namespace std;
const int N = 2000010;
int V,Q,p[N],sum[N],rnk[N];
int fi(int x){
    if(p[x]==x){
        return x;
    }
    return fi(p[x]);
}
int ge(int u){
    if(p[u]==u){
        return sum[u];
    }
    return ge(p[u])+sum[u];
}
void uni(int u, int v){
    u = fi(u);
    v = fi(v);
    if(u != v){
        if(rnk[u] < rnk[v])
            swap(u,v);
        if(rnk[u] == rnk[v])
            rnk[u]++;
        p[v] = u;
        sum[v] -= sum[u];
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> Q;
    for(int i=1; i<=V; i++){
        p[i]=i;
        sum[i]=0;
    }
    while(Q--){
        string str;
        cin >> str;
        if(str == "join"){
            int u,v;
            cin >> u >> v;
            uni(u,v);
        }else if(str == "add"){
            int x,u;
            cin >> u >> x;
            u = fi(u);
            sum[u]+=x;
        }else{
            int u,ans=0;
            cin >> u;
            ans = ge(u);
            cout << ans << "\n";
        }
        /*for(int i=1; i<=V; i++)
            cout << sum[i] << " ";
        cout << "\n";*/
    }
}
