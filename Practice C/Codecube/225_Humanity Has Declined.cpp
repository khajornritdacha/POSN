#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
const int N=200010;
int a[N],cnt[N],n,k,q,ans[N];
main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> q;
	for(int i=1;i<=n;i++)
        cin >> a[i];
    int j=1,sat=0;
    if(a[1]<=k){ sat++; ++cnt[a[1]];}
    for(int i=1;i<=n;i++){
        while(sat<k&&j<=n){
            j++;
            if(a[j]<=k&&++cnt[a[j]]==1)
                sat++;
        }
        if(sat==k) ans[i]=j;
        else ans[i]=n+1;
        //cout << sat << " " << j << "\n";
        if(a[i]<=k&&--cnt[a[i]]==0)
            sat--;
    }
    /*for(int i=1;i<=n;i++)
        cout << ans[i] << " ";
    cout << "\n";*/
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << (r>=ans[l] ? "YES\n" : "NO\n");
    }
}
