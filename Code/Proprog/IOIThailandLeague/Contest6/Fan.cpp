#include<bits/stdc++.h>
using namespace std;
int a,b,n;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        x%=360;
        if(x%60 == 0) continue;
        if((x > 0 and x < 60) or (x > 120 and x < 180) or (x > 240 and x < 300))
            a++;
        else
            b++;
    }
    cout << a << " " << b << "\n";
    if(a > b)
        cout << "Joy";
    else if(b > a)
        cout << "Jaew";
    else
        cout << "Draw";
}
