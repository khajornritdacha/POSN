#include<bits/stdc++.h>
using namespace std;
string a,b,ans;
int c[305][305];
void LCM(string a,string b){
    int n=a.size();
    int m=b.size();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0)
                c[i][j] = 0;
            else if(a[i-1]==b[j-1]){
                c[i][j] = 1+c[i-1][j-1];
               // cout << a[i-1];
            }else if(c[i-1][j]>c[i][j-1]){
                c[i][j] = c[i-1][j];
            }else{
                c[i][j] = c[i][j-1];
            }
        }
    }
    int i=n;
    int j=m;
    while(i>0&&j>0){
        if(a[i-1]==b[j-1]){
            ans.push_back(a[i-1]);
            i--,j--;
        }else if(c[i-1][j]>c[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
}
main(){
    cin >> a >> b;
    LCM(a,b);
    cout << "The longest common subsequence is \"";
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i];
    }
    cout << "\"\nLength :";
    cout << c[a.size()][b.size()] << "\n";
   /* for(int i=0;i<=a.size();i++){
        for(int j=0;j<=b.size();j++){
           cout << c[i][j] << " ";
    }
        cout << "\n";
    }*/
}
