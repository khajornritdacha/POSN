#include<bits/stdc++.h>
using namespace std;

int n,K,a[1010],mx,pos1,pos2;

main(){
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(a[i]+a[j] > mx and a[i]+a[j] <= K){
                mx = a[i]+a[j];
                pos1 = i;
                pos2 = j;
            }
        }
    }
    cout << pos1 << " " << pos2;
}
