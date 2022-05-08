#include<bits/stdc++.h>
using namespace std;

const int N = 1e2+10;
int n,x[N],y[N],mx;

main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            for(int k=j+1; k<=n; k++){
                if((y[i] == y[j] or y[i] == y[k] or y[j] == y[k]) and (x[i] == x[j] or x[i] == x[k] or x[j] == x[k])){
                    int b,h;
                    if(x[i] == x[j])
                        h = abs(y[j]-y[i]);
                    else if(x[i] == x[k])
                        h = abs(y[k]-y[i]);
                    else if(x[j] == x[k])
                        h = abs(y[k]-y[j]);
                    if(y[i] == y[j])
                        b = abs(x[i]-x[j]);
                    else if(y[i] == y[k])
                        b = abs(x[i]-x[k]);
                    else if(y[j] == y[k])
                        b = abs(x[j]-x[k]);

                    mx = max(mx, b*h);
                }
            }
        }
    }
    cout << mx;
}

