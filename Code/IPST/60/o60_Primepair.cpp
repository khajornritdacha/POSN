#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e6+10;
int lim=1e6,f[N],chk[N],A,B,C,D;

main(){
    for(int i=2; i<=lim; i++){
        if(!chk[i]){
            f[i] = 1;
            for(int j=i; j<=lim; j+=i){
                chk[j] = i;
            }
        }
    }
    for(int i=2; i<=lim; i++){
        if(!f[i]){
            f[i] = 1+f[i/chk[i]];
        }
    }

    if(DEBUG){
        for(int i=1; i<=10; i++){
            cout << "I " << i << " = " << f[i] << "\n";
        }
    }

    cin >> A >> B >> C >> D;
    int res[2] = {}, ans=0;
    for(int i=2; i<=lim; i++){
        int tmp[2]={};
        for(int j=i; j<=lim; j+=i){
            if(A <= j and j <= B)
                tmp[0] =  j;
            if(C <= j and j <= D)
                tmp[1] = j;
        }
        if(tmp[0] and tmp[1]){
            if(f[i] > ans){
                ans = f[i];
                res[0] = tmp[0];
                res[1] = tmp[1];
            }else if(f[i] == ans){
                if(tmp[0]+tmp[1] > res[0]+res[1]){
                    res[0] = tmp[0];
                    res[1] = tmp[1];
                }else if(tmp[0]+tmp[1] == res[0]+res[1]){
                    if(tmp[0] > res[0]){
                        res[0] = tmp[0];
                        res[1] = tmp[1];
                    }
                }
            }
        }
    }
    //cout << ans << "\n";
    cout << res[0] << " " << res[1] << "\n";
}
