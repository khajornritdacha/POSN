#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
char a[N][N];
int n,m;

main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=m; i++){
        char code;
        int val;
        cin >> code >> val;
        if(code == 'L'){
            for(int j=1; j<=n; j++){
                if(a[val][j] != 'x')
                    break;
                a[val][j] = '.';
            }
        }else if(code == 'R'){
            for(int j=n; j>=1; j--){
                if(a[val][j] != 'x')
                    break;
                a[val][j] = '.';
            }
        }else if(code == 'U'){
            for(int i=1; i<=n; i++){
                if(a[i][val] != 'x')
                    break;
                a[i][val] = '.';
            }
        }else if(code == 'D'){
            for(int i=n; i>=1; i--){
                if(a[i][val] != 'x')
                    break;
                a[i][val] = '.';
            }
        }else if(code == 'A'){
            for(int j=1; j<=n; j++){
                if(a[val][j] != '#')
                    a[val][j] = 'x';
            }
        }else{
            for(int i=1; i<=n; i++){
                if(a[i][val] != '#')
                    a[i][val] = 'x';
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
}
