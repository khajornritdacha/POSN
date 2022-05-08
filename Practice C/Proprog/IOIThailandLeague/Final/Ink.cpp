#include<bits/stdc++.h>
using namespace std;

int n;
long double S;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S >> n;
    for(int i=1; i<=n; i++){
        long double x,y;
        cin >> x >> y;
        cout << setprecision(0) << fixed << ceil(3.14159265358979323846*(x*x+y*y)/1.0/S) << "\n";
    }
}
