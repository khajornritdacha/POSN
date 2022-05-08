#include<bits/stdc++.h>
using namespace std;
string a,b;
int cnt[2][100005];
void LCS(string a,string b){
    int n=a.size();
    int m=b.size();
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j==0)
                cnt[i%2][j] = 0;
            else if(a[i-1]==b[j-1]){
                cnt[i%2][j] = 1+cnt[(i-1)%2][j];
               // cout << a[i-1];
            }else if(cnt[(i-1)%2][j]>cnt[i%2][j-1]){
                cnt[i%2][j] = cnt[(i-1)%2][j];
            }else{
                cnt[i%2][j] = cnt[i%2][j-1];
            }
        }
    }
}
main(){
    ///LCS's string cannot be printed.
    cin >> a >> b;
    LCS(a,b);
    cout << cnt[a.size()%2][b.size()] << "\n";
}
