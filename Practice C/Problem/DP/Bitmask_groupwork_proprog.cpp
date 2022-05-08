#include<bits/stdc++.h>
using namespace std;
int num=1;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(1){
        int n,mx=-1;
        cin >> n;
        int a[n+10];
        int b[n+10];
        if(n==0) return 0;
        for(int i=1; i<=n; i++){
            int x,y,z,s;
            cin >> x >> y >> z >> s;
            x--;
            y--;
            z--;
            a[i]=(1<<x)|(1<<y)|(1<<z);
            b[i]=s;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                for(int k=1; k<=n; k++){
                    int temp=a[i]|a[j]|a[k];
                    if(temp==(1<<9)-1){
                        mx=max(mx,b[i]+b[j]+b[k]);
                        //cout << i << " " << j << " " << k << "\n";
                    }
                }
            }
        }
        cout << "Case " << num++ << ": " << mx << "\n";
    }
}
