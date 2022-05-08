#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,a[N],qs[N],ans=1e9,a0,a1;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        qs[i] += qs[i-1]+a[i];
    }
    for(int i=2; i<n; i++){
        for(int j=i+1; j<=n; j++){
            int one = qs[i-1];
            int two = qs[j-1]-qs[i-1];
            int three = qs[n]-qs[j-1];
            int tmp = max({one, two, three})-min({one, two, three});
            if(tmp < ans){
                ans = tmp;
                a0 = i;
                a1 = j;
            }
        }
    }
    cout << a0 << " " << a1 << "\n";
}
