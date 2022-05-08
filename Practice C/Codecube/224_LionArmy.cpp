#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
int n,m;
long long cmp;
vector<int> vec;
bool cd;
int _fi(int x){
    if(vec[x]==x) return x;
    return vec[x]=_fi(vec[x]);
}
void uni(int u1,int v1,int u2,int v2){
    u1=_fi(u1);
    v1=_fi(v1);
    int cnt=0;
    if(u1!=v1){
       cnt++;
       vec[u1]=v1;
    }
    u2=_fi(u2);
    v2=_fi(v2);
    if(u2!=v2){
        cnt++;
        vec[u2]=v2;
    }
    if(cnt==2)
        cmp--;
    else if(cnt==1){
        cd=1;
    }
}
long long po(long long b, long long p){
    if(p==0) return 1;
    if(p==1) return b;
    long long temp=po(b,p/2);
    temp%=MOD;
    temp*=temp;
    temp%=MOD;
    if(p%2)
        temp*=b;
        temp%=MOD;
    return temp;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    cmp=n;
    vec.resize(n*2+1);
    for(int i=1; i<=2*n; i++){
        vec[i]=i;
    }
    for(int i=0; i<m; i++){
        int t,u,v;
        cin >> t >> u >> v;
        if(cd){
            cout << 0 << "\n";
            continue;
        }
        if(t==0){
            uni(u,v+n,u+n,v);
        }else{
            uni(u,v,u+n,v+n);
        }
        if(cd){
            cout << 0 << "\n";
            continue;
        }
        cout << po(2,cmp) << "\n";
    }
}
