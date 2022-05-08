#include<bits/stdc++.h>
using namespace std;

int X,Y,xo,xt,yo,yt;

main(){
    cin >> X >> Y >> xo >> yo >> xt >> yt;
    int sz1 = (X-xo)*(Y-yt);
    int sz2 = (X-xt)*(Y-yo);
    int sz3 = max(0, X-xo-xt)*Y;
    int sz4 = max(0, Y-yo-yt)*X;
    cout << max({sz1, sz2, sz3, sz4});
}
