#include<bits/stdc++.h>
using namespace std;
int i,j,nq,n,ans[100005],l,r,mid;
long long a[100005],q;
main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
    cin >> n >> nq;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    /*for(i=0;i<n;i++){
        cout << a[i] << "\n";
    }*/
    for(i=0;i<nq;i++){
        cin >> q;
        r = n-1;
        l = 0;
        while(l<=r){
            mid = (l+r)/2;
            if(a[mid]>q){
                r = mid-1;
                //cout << "AA\n";
            }else if(a[mid]<q){
                l = mid+1;
                //cout << "bb\n";
            }else if(a[mid]==q){
                ans[i] = 1;
                break;
            }
        }
    }
    for(i=0;i<nq;i++){
        if(ans[i]==1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}
