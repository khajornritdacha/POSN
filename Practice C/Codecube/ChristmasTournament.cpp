#include<bits/stdc++.h>
using namespace std;
int t;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        int x,y,z;
        cin >> x >> y >> z;
        if(x>=1&&y>=1&&z>=1)
            cout << "YES\n";
        else{
            if(!x) cnt++;
            if(!y) cnt++;
            if(!z) cnt++;
            if(cnt==2)
                cout << "NO\n";
            else{
                int p=0;
                if(x==1) p++;
                if(y==1) p++;
                if(z==1) p++;
                if(p==2) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}
