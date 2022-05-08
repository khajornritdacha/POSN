#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[5];
int n,one[3][10],two[3][10][10],three[10][10][10];
long long ans;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin >> a[j];
            a[j]-='0';
            ans+=one[j][a[j]]++;
        }
        ans-=two[0][a[0]][a[1]]++;
        ans-=two[1][a[0]][a[2]]++;
        ans-=two[2][a[1]][a[2]]++;
        ans+=three[a[0]][a[1]][a[2]]++;
    }
    cout << ans << "\n";
}
