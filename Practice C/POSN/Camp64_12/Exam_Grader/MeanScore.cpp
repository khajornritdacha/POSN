#include<bits/stdc++.h>
using namespace std;

double a[2][110],avg[2],sa;
int n[2],lo[2],al;

main(){
    for(int i=0; i<2; i++){
        while(true){
            double x;
            cin >> x;
            if(x < 0)
                break;
            a[i][n[i]++] = x;
            avg[i] += x;
            sa += x;
        }
        avg[i] /= n[i];
    }
    sa/=(n[0]+n[1]);
    cout << setprecision(2) << fixed << avg[0] << " " << avg[1] << " " << sa << "\n";
    for(int i=0; i<2; i++){
        for(int j=0; j<n[i]; j++){
            if(a[i][j] < avg[i])
                lo[i]++;
            if(a[i][j] < sa)
                al++;
        }
    }
    cout << lo[0] << " " << n[0]-lo[0] << " " << lo[1] << " " << n[1]-lo[1] << " " << al << " " << n[0]+n[1]-al;
}
