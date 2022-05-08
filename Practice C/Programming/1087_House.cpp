#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int a[305][305],b[305][305],mx,r,c,k;
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c >> k;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> a[i][j];
            b[i][j]=a[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            for(int o=i+1;o<=i+k&&o<=r;o++){
                if((o-i)%2){
                    b[o][j]-=a[i][j];
                    b[i][j]-=a[o][j];
                }
                else{
                    b[o][j]+=a[i][j];
                    b[i][j]+=a[o][j];
                }
            }
            for(int o=j+1;o<=j+k&&o<=c;o++){
                if((o-j)%2){
                    b[i][o]-=a[i][j];
                    b[i][j]-=a[i][o];
                }
                else{
                    b[i][o]+=a[i][j];
                    b[i][j]+=a[i][o];
                }
            }
            mx=max(mx,b[i][j]);
        }
    }
    /*for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << mx;
}
