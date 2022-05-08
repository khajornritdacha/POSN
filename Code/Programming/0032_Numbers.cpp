#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
int n,cnt[15];
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(int i=1; i<=9; i++)
        if(cnt[i]){
            cout << i;
            cnt[i]--;
            break;
        }
    for(int i=0; i<=9; i++){
        for(int j=0; j<cnt[i]; j++)
            cout << i;
    }
}
