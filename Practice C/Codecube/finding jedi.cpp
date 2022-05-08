#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000105],m,ans=0;
bool visit[1000105];
main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a[x]+=1;
    }
    for(int i=0;i<=m;i++){
        int x = m-i;
        if(a[x]==0||a[i]==0)
            continue;

        if(visit[x]==false){
        if(x==i&&a[x]>1){
            int temp = a[x]-1;
            ans+=((temp+1)*(a[x]/2));
            if(a[x]%2==0)
                ans-=(a[x]/2);
        }
        else if(x!=i)
            ans+=(a[x]*a[i]);
        visit[x] = true;
        visit[i] = true;
        }
        //cout << a[i] << endl;
    }
    cout << ans;
    return 0;
}
