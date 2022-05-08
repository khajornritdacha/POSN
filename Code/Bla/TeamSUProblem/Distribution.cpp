#include<bits/stdc++.h>
using namespace std;
int n,m,a[650][650],cd[650],ans;
main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    for(int i1=1; i1<=n; i1++){
        for(int i2=i1; i2<=n; i2++){
            int st=0;
            for(int j=1; j<=m; j++){
                if(i2==i1) cd[j]=a[i2][j];
                if(cd[j]!=cd[j-1]) st=j-1;
                if(a[i2][j]==cd[j]){
                    ans=max(ans,(j-st)*(i2-i1+1));
                    //cout << ans << " ";
                }else{
                    cd[j]=-1;
                }
            }
            //cout << "\n";
        }
        //cout << "\n\n";
    }
    cout << ans;
}
