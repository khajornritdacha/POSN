#include<bits/stdc++.h>
using namespace std;
int m,n,x,y;
int ex(int a, int b, int &xo, int &yo){
    if(a==0){
        xo=0;
        yo=1;
        return b;
    }
    int p,q,r;
    r = ex(b%a, a, p, q);
    xo = q-(b/a)*p;
    yo = p;
    return r;
}
main(){
    cin >> m >> n;
    cout << ex(m, n, x, y) << " " << x << " " << y;

}
