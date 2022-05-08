#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+100;
int n,m,a[N],st,di=1;
int cal(int k){
    return (st+k*di+n)%n;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m;i++){
        int x,y;
        char c;
        cin >> c;
        if(c == 'a'){
            cin >> x >> y;
            x--; y--;
            swap(a[cal(x)], a[cal(y)]);
        }else if(c == 'b'){
            cin >> x >> y;
            x--;
            a[cal(x)] = y;
        }else if(c == 'c'){
            cin >> x;
            x--;
            st = cal(x);
            di *= -1;
        }else{
            cin >> x; x--;
            cout << a[cal(x)] << "\n";
        }
    }
}
