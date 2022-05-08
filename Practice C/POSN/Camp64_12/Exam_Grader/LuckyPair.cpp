#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int n,K,a[N],cnt;


main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cin >> K;

    /*if(K == 12){
        cout << "No";
        return 0;
    }*/

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(a[i] + a[j] == K){
                cout << a[i] << " " << a[j] << "\n";
                cnt++;
            }
        }
    }

    if(cnt == 0)
        cout << "No";
}
