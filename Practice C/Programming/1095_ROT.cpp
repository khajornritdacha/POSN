#include<bits/stdc++.h>
using namespace std;
int n,m,t,mr,mc;
char a[100][100],b[100][100];
main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    cin >> t;
    while(t>=90){
        t-=90;
        for(int i=n,c=1; i>=1; i--,c++){
            for(int j=1,r=1; j<=m; j++,r++){
                b[r][c] = a[i][j];
            }
        }
        swap(n,m);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                a[i][j] = b[i][j];
            }
        }
    }
    if(t>=45){
        t-=45;
        for(int i=0; i<50; i++) for(int j=0; j<50; j++) b[i][j] = ' ';
        for(int i=1; i<=n; i++){
            int r = i, c = n-i+1;
            for(int j=1; j<=m; j++,r++,c++){
                //cout << "I&J&R&C : " << i << " " << j << " " << r << " " << c << "\n";
                b[r][c] = a[i][j];
                mr = max(r, mr);
                mc = max(c, mc);
            }
        }
        for(int i=1; i<=mr; i++){
            for(int j=1; j<=mc; j++){
                cout << b[i][j];
                if(isalpha(b[i][j]) and !isalpha(b[i][j+2]))
                    break;
            }
            cout << "\n";
        }
        return 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
}
