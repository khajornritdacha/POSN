#include<bits/stdc++.h>
using namespace std;

const int N = 2510;
using ll = long long;

int a[N],dp[N],st[N],mx,n;

void pri(int i){
    if(st[i] != i) pri(i-1);
    cout << a[i] << " ";
}

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(dp[i-1]+a[i] > a[i]){
            st[i] = st[i-1];
            dp[i] = dp[i-1]+a[i];
        }else{
            dp[i] = a[i];
            st[i] = i;
        }
        if(dp[i] > dp[mx])
            mx = i;
    }

    if(mx == 0){
        cout << "Empty sequence\n";
    }else{
        pri(mx);
        cout << "\n" << dp[mx] << "\n";
    }
    return 0;
}
