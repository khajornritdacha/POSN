#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,K,cnt;
main(){
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        int mx1,mx2;
        mx1 = mx2 = 0;
        for(int j=0; j<3; j++){
            int x;
            cin >> x;
            if(x > mx1)
                swap(x, mx1);
            if(x > mx2)
                swap(x, mx2);
        }
        if(cnt < K and mx1 >= 8 and mx2 >= 8){
            cout << "Yes";
            cnt++;
        }else{
            cout << "No";
        }
        cout << "\n";
    }
    cout << cnt << "\n";
}
