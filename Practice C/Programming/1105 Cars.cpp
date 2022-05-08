#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,k;
main(){
    a[0]=1e9;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n+1,greater<int>());
    printf("%d",a[k]);
}
