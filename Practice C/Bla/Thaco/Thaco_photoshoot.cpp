#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
int N,K,ep[520],ans[520],a[520],st[520],ed[520],mx=0;
bool visit[520];
vector<pi> vec;
void solve(int lv=1){
    if(lv==N+1){
        int sum=0;
        for(int i=1; i<=K; i++){
            int mn=2e9;
            int mmx=0;
            for(int j=st[i]; j<=ed[i]; j++){
                if(a[j]<mn){
                    mn=a[j];
                }
                if(a[j]>mmx){
                    mmx=a[j];
                }
            }
            sum+=(mmx-mn);
        }
        if(sum>mx){
            for(int i=1; i<=N; i++){
                ans[i]=a[i];
            }
            mx=sum;
        }
        return;
    }
    for(int i=1; i<=N ;i++){
        if(!visit[i]){
            visit[i]=true;
            a[lv]=i;
            solve(lv+1);
            visit[i]=false;
        }
    }
}
main(){
    ios_base::sync_with_stdio(0);   cin.tie(0);
    cin >> N >> K;
    for(int i=1; i<=K; i++){
        int l,r;
        cin >> l >> r;
        st[i]=l;
        ed[i]=r;
        ep[l]++;
        ep[r+1]--;
    }
    if(K>20&&N>9){
    for(int i=1; i<=N; i++){
        ep[i]+=ep[i-1];
        vec.emplace_back(ep[i],i);
    }
    sort(vec.rbegin(),vec.rend());
    bool cd;
    int mx=N;
    int mn=1;
    for(int i=0; i<vec.size(); i++){
        if(cd){
            ans[vec[i].second]=mx;
            mx--;
            cd=false;
        }else{
            ans[vec[i].second]=mn;
            mn++;
            cd=true;
        }
    }
    for(int i=1; i<=N; i++){
        cout << ans[i] << " ";
    }
    }else{
        solve();
        for(int i=1; i<=N; i++){
        cout << ans[i] << " ";
    }
    }

}
