#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
const int N=200010;
int A[N],n,q,a,b,s,e,com[N],w[N],cnt,cou;
bool visit[N];
void dfs(int u,int t){
    if(visit[u]) return;
    visit[u]=true;
    com[u]=cou;
    w[u]=cnt++;
    dfs(A[u],t);
}
bool query(){
    if(com[s]!=com[e])
        return((com[s]==com[a]&&com[e]==com[b])||(com[e]==com[a]&&com[s]==com[b]));
    else{
        if(com[s]!=com[a]||com[s]!=com[b])
            return true;
        if(w[s]>w[e]) swap(s,e);
        return ((w[s]<=w[a]&&w[a]<w[e])==(w[s]<=w[b]&&w[b]<w[e]));
    }
}
main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++)
        cin >> A[i];
    for(int i=1;i<=n;i++)
        if(!visit[i]){
            cnt=1;
            dfs(i,++cou);
        }
    while(q--){
        cin >> s >> e >> a >> b;
        cout << (query() ? "DEAD\n" : "SURVIVE\n");
    }
}
