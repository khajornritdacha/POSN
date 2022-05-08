#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int MOD=1e9+7;
void expo(int mat[4][4],int p){
    int temp[4][4]={{0,1,1,1},{1,0,1,1},{1,1,0,1,},{1,1,1,0}};
    int chua[4][4];
    if(p==1) return;
    expo(mat,p/2);
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            chua[i][j]=0;
            for(int k=0; k<4; k++){
                chua[i][j]+=((mat[i][k]*mat[k][j])%MOD)%MOD;
            }
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            mat[i][j]=chua[i][j]%MOD;
        }
    }
    if(p%2){
       for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            chua[i][j]=0;
            for(int k=0; k<4; k++){
                chua[i][j]+=((mat[i][k]*temp[k][j])%MOD)%MOD;
            }
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            mat[i][j]=chua[i][j]%MOD;
        }
    }
    }
}
int _fi(int n){
    if(n==1) return 0;
    int mat[4][4]={{0,1,1,1},{1,0,1,1},{1,1,0,1,},{1,1,1,0}};
    expo(mat,n);
    return mat[3][3]%MOD;
}
main(){
    cin >> n;
    cout << _fi(n);
}
