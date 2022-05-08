#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n,m,a[N],b[N],c[N],cnt[N],cntall,want[N],ans[N],pos[N];
stack<int> st[N];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        bool ok = false;
        cntall=0;
        cin >> n >> m;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        for(int i=1; i<=n; i++){
            cin >> b[i];
            if(a[i] != b[i]){
                cntall++;
                want[b[i]]++;
                st[b[i]].push(i);
            }else{
                cnt[a[i]]++;
                pos[a[i]] = i;
            }
        }
        for(int i=1; i<=m; i++){
            cin >> c[i];
        }
        for(int i=m; i>=1; i--){
                //cout << "I: " << i << " "  << c[i] << " ";
            if(want[c[i]] != 0 || cnt[c[i]] != 0){
                if(want[c[i]] != 0){
                    want[c[i]]--;
                    cntall--;
                    cnt[c[i]]++;
                    ans[i] = st[c[i]].top();
                    pos[c[i]] = ans[i];
                    st[c[i]].pop();
                }else{
                    ans[i] = pos[c[i]];
                }
                ok=true;
            }else{
                if(!ok){
                    cntall = 1e9; break;
                }else{
                    ans[i] = ans[i+1];
                }
            }
        }
        //cout << "TSET\n";
        if(cntall != 0)
            cout << "No\n";
        else{
            cout << "Yes\n";
            for(int i=1; i<=m; i++)
                cout << ans[i] << " \n"[i==m];
        }
        for(int i=1; i<=max(n,m); i++){
            a[i] = b[i] = c[i] = ans[i] = want[i] = cnt[i] = pos[i] = 0;
            while(!st[i].empty())
                st[i].pop();
        }
    }
}
///https://codeforces.com/problemset/problem/1481/C
