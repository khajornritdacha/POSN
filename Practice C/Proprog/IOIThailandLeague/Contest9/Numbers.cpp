#include<bits/stdc++.h>
using namespace std;

int n,cnt[10];

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(int i=1; i<=9; i++){
        if(cnt[i]){
            cout << i;
            cnt[i]--;
            break;
        }
    }
    for(int i=0; i<=9; i++){
        while(cnt[i]){
            cout << i;
            cnt[i]--;
        }
    }
}
