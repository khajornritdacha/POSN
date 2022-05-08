#include <bits/stdc++.h>
using namespace std;


int main(void){
    string A,P;
    cin >> A >> P;
    int pi[P.size()+10] = {};

    for(int i = 1; i < P.size(); i++){
        int j = pi[i-1];
        while(j and P[j] != P[i])
            j = pi[j-1];
        if(P[j] == P[i])
            j++;
        pi[i] = j;
    }

    int ans = 0;
    for(int i = 0, idx = 0; i < A.size(); i++){
        while(idx > 0 and P[idx] != A[i])
            idx = pi[idx-1];
        if(P[idx] == A[i])
            idx++;
        if(idx == P.size()){
            ans++;
            idx = pi[idx-1];
        }
    }
    cout << ans << "\n";
    return 0;
}
