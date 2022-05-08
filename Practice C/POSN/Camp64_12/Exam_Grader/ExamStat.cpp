#include<bits/stdc++.h>
using namespace std;

int S,n,mn[1010],mx[1010],sc[1010],a[1010][1010],st[1010],sa;
double allavg,avg[1010];

main(){
    cout << setprecision(2) << fixed;
    cin >> S >> n;
    memset(mn, 127, sizeof(mn));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=S; j++){
            cin >> a[i][j];
            mn[j] = min(mn[j], a[i][j]);
            mx[j] = max(mx[j], a[i][j]);
            sc[j] += a[i][j];
            st[i] += a[i][j];
            sa += a[i][j];
        }
    }
    for(int i=1; i<=S; i++){
        double tmp = 0;
        avg[i] = 1.0*sc[i]/n;
        cout << mn[i] << " " << mx[i] << " " << avg[i] << " ";
        for(int j=1; j<=n; j++){
            tmp += (a[j][i]-avg[i])*(a[j][i]-avg[i]);
        }
        cout << sqrt(tmp/(n-1)) << "\n";
        allavg += avg[i];
    }
    cout << *min_element(st+1, st+n+1) << " " << *max_element(st+1, st+1+n) << " " << allavg << " ";
    double tmp = 0;
    for(int i=1; i<=n; i++){
        tmp += (st[i]-allavg)*(st[i]-allavg);
    }
    double allsd = sqrt(1.0*tmp/(n-1));
    cout << allsd << "\n";
    int lo = 0;
    for(int i=1; i<=n; i++){
        if(allavg-sqrt(allsd) > st[i]){
            lo++;
        }
    }
    cout << n-lo << " " << lo;
}
