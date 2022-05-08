#include<bits/stdc++.h>
using namespace std;
int n,m,want[200],cnt[200],wtp,type,ans;
char G[3010],S[3000010];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> G+1 >> S+1;
    for(int i=1; i<=n; i++){
        if(++want[G[i]] == 1)
            wtp++;
    }
    for(int i=1; i<=m; i++){
        bool ok = true;
        cnt[S[i]]++;
        if(i >= n+1)
            cnt[S[i-n]]--;
        for(int j='A'; ok and j<='z'; j++){
            if(cnt[j] != want[j])
                ok = false;
        }
        if(ok)
            ans++;
    }
    cout << ans << "\n";
}
