#include<bits/stdc++.h>
using namespace std;
int n,i,q,j,x,ans[350000],cou,pas;
long long l,r,a[350000],b,mid,midtemp;
main(){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d %lld",&x,&b);
        l = 0;
        r = n;
        midtemp = 0;
        if(a[n-1]<b){
            ans[i] = 0;
            continue;
        }
        else {
            while(l<=r){
                mid = (l+r)/2;
                if(a[mid]>=b){
                    midtemp = mid;
                    r = mid-1;
                   //cout << "\n" << midtemp<<"\n";
                }else if(a[mid]<b){
                    l = mid+1;
                }
        }
        cou=0;
        j=0;
        while(a[midtemp+j]==a[midtemp+1+j]){
            cou++;
            j++;
        }
           //cout << midtemp << " " << a[midtemp] <<"\n\n";
            if(x==0)
            {
                ans[i] = n-midtemp;
            }
            else if(x==1)
            {
                if(b<a[midtemp]){
                    ans[i] = n-midtemp;
                }
                else{
                    ans[i] = n-midtemp-1-cou;
                }
            }
        }
    }
    for(i=0;i<q;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
