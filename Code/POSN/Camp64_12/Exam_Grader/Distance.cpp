#include<bits/stdc++.h>
using namespace std;
double S,h,m,ans;
main(){
    cin >> S >> h >> m;
    ans = h*S+(S/60*m);
    cout << setprecision(1) << fixed << abs(ans) << "\n";
    if(ans < 0)
        cout << "reverse";
}
