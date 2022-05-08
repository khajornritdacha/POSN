#include<bits/stdc++.h>
using namespace std;
const int N = 3e2+10;
int n,m,r1,c1,s1,r2,c2,s2,T=110;
char a[N][N];
main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i+T][j+T];
        }
    }
    bool fo = false;
    for(int i=1; i<=n and !fo; i++){
        for(int j=1; j<=m; j++){
            if(a[i+T][j+T] == 'x'){
                r1 = i, c1 = j, fo = true;
                while(a[i+T][j+s1+T] == 'x' and a[i+s1+T][j+T] == 'x')
                    s1++;
                break;
            }
        }
    }
    for(int i=r1; i<r1+s1; i++){
        for(int j=c1; j<c1+s1; j++){
            a[i+T][j+T] = '.';
        }
    }
    //for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cout << a[i+T][j+T] << " \n"[j==m];
    fo = false;
    for(int i=n; i>=1 and !fo; i--){
        for(int j=m; j>=1; j--){
            if(a[i+T][j+T] == 'x'){
                r2 = i, c2 = j, fo = true;
                while(a[i-s2+T][j+T] == 'x' or a[i+T][j-s2+T] == 'x')
                    s2++;
                break;
            }
        }
    }
    if(s2 == 0){
        for(int i=0; i<2; i++)
            cout << r1 << " " << c1 << " " << s1 << "\n";
    }else{
        cout << r1 << " " << c1 << " " << s1 << "\n";
        cout << max(1, r2-s2+1) << " " << max(1, c2-s2+1) << " " << s2 << "\n";
    }
}
