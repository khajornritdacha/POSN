#include<bits/stdc++.h>
using namespace std;
int i,v,x,l,c,n;
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int j=1;j<=n;j++){
        int y = j;
        c+=y/100;
        y%=100;
        if(y>=90){
            x++; c++;
        }else if(y>=50){
            l++;
            y%=50;
            x+=y/10;
        }else if(y>=40){
            l++;
            x++;
        }else{
            x+=y/10;
        }
        y%=10;
        if(y>=9){
            i++; x++;
        }else if(y>=5){
            v++;
            y%=5;
            i+=y;
        }else if(y>=4){
            v++;
            i++;
        }else{
            i+=y;
        }
    }
    cout << i << " " << v << " " << x << " " << l << " " << c;
}
