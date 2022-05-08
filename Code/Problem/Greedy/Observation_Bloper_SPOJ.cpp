#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 510;

int n,S,ans[N];

///https://www.spoj.com/problems/BLOPER/

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> S;
    if(n == 1){
        if(S == 1) cout << "1\n";
        else cout << "Impossible\n";
        return 0;
    }
    S--;

    //cout << S << "\n";
    for(int i = n; i >= 3; i--){
        int k = i-1;
        int tl = (k+1)*k/2-1;
        int ns = S-i;
        //cout << i << " " << ns << " " << tl << "\n";
        //cout << (ns&1) << " " << (tl&1) << " "  << -1*(tl-4) << "\n";

        if(ns == tl or ((ns&1) == (tl&1) and tl-4 >= ns and ns >= -1*(tl-4)) or ns == -tl){ ///check if let i be positive
            ans[i] = i; ///i can be positive if and only if (read inside if) because 2...i-1 can form sum -tl or [-tl-4, tl-4] or tl
            S -= i;
        }else{
            ans[i] = -i;
            S += i;
        }
    }

    //cout << S << "\n";
    if(S == -2){
        ans[2] = -2;
    }else if(S == 2){
        ans[2] = 2;
    }else{
        cout << "Impossible\n";
        return 0;
    }

    cout << "1";
    for(int i = 2; i <= n; i++){
        if(ans[i] > 0) cout << "+";
        cout << ans[i];
    }
    return 0;
}
