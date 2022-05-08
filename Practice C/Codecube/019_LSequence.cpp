#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e3+10;

int a[N],ans[N],n,K;

bool re(int &i, int &lef, int pos){
    //cout << "CUR : " << i << " " << lef << " " << pos <<  "\n";
    for(int j=i+1; j<=n and j-i<=lef; j++){
        if(a[j] < ans[pos]){
            ans[pos] = a[j];
            lef -= j-i;
            i = j;
            return true;
        }
    }
    return false;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    int lef = K, i = 1, pos = 1;
    while(i <= n){
        ans[pos] = a[i];

        while(re(i, lef, pos));

        pos++; i++;
    }

    for(int i=1; i<=n-K; i++)
        cout << ans[i] << " ";
}

