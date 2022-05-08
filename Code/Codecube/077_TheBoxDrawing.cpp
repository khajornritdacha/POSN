#include<bits/stdc++.h>
using namespace std;

const int N = 1e2+10;
char a[N][N];
int n;

main(){
    cin >> n;
    for(int i=1; i<=3*n; i++){
        for(int j=1; j<=2*n+1; j++){
            a[i][j] = '-';
        }
    }

    for(int i=n; i<=2*n-1; i++){
        for(int j=2; j<=2*n; j++){
            a[i][j] = '#';
        }
    }

    int num = n+1;
    for(int i=1; i<n; i++){
        for(int j=num; j<=num+2*(i-1); j++){
            a[i][j] = '#';
        }
        num--;
    }

    num = 3;
    for(int i=2*n, cou=n-1; i<=3*n; i++, cou--, num++){
        for(int j=num ; j<=num+2*cou-2; j++){
            a[i][j] = '#';
        }
    }

    int col = n+1, row = 3*n-3;
    for(int i=0; i<n; i++, row--){
        a[row][col] = '-';
    }
    for(int i=0; i<n-2; i++, row--){
        a[row][col-i-1] = '-';
        a[row][col+i+1] = '-';
    }

    for(int i=1; i<=3*n-3; i++){
        for(int j=1; j<=2*n+1; j++){
            if(i == 1 or i == 3*n-3){
                cout << '-';
            }else{
                cout << a[i][j];
            }
            cout << " ";
        }
        cout << "\n";
    }
}
