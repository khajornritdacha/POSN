#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
int a,b,c,d;
main(){
    cin >> a >> b >> c;
    for(int i=1; i<=a; i++){
        if(a%i != 0) continue;
        int fir = i, fis = a/i;
        for(int j=-100; j<=100; j++){
            for(int k=-100; k<=100; k++){
                if(j*k != c) continue;
                if(fir*k+fis*j == b){
                    cout << fir << " " << j << " " << fis << " " << k;
                    return 0;
                }
            }
        }
    }
    cout << "No Solution";
}
