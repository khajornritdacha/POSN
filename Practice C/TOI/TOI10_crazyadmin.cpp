#include<bits/stdc++.h>
using namespace std;
int m,o,maxx,a[105],ans=1e9;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> o;
    for(int i=0;i<o;i++){
        cin >> a[i];
        maxx = max(maxx,a[i]);
    }
    if(m>=o){ cout << maxx; return 0;}
    int l=0,r=1e9,mid,code=0;
    while(l<=r){
        mid = (l+r)/2;
        code = 0;
        int sen = mid,temp=0,jum=1;
        for(int i=0;i<o;i++){
            if(sen<a[i]){
                code = 1;
                break;
            }
            if(temp+a[i]>sen){
                temp=a[i];
                jum++;
            }else{
                temp+=a[i];
            }
            if(jum>m){
                code = 1;
                break;
            }
        }
        if(code==1){
            l = mid+1;
        }else{
            ans = min(ans,mid);
            r = mid-1;
        }
    }
    cout << ans;
}
