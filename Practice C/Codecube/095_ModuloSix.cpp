#include<bits/stdc++.h>
using namespace std;

int n,S,cnt[5];

main(){
    cin >> n >> S;
    if(n == 1){
        if(S == 6)
            cout << 6;
        else
            cout << -1;
        return 0;
    }
    if(S%3 != 0 or S > (n-1)*9+6 or S < 3){
        cout << -1;
        return 0;
    }

    if(S == 3){
        cout << 3;
        for(int i=0; i<n-1; i++)
            cout << 0;
        return 0;
    }

    int now = S, di = n;
    while(now > 0 and now%9 != 0 and di > 0){
        cnt[1]++;
        now -= 6;
        di--;
    }

    while(now > 0 and di > 0){
        cnt[0]++;
        now-=9;
        di--;
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<cnt[i]; j++)
            if(i == 0)
                cout << 9;
            else
                cout << 6;
    }

    for(int i=0; i<di; i++)
        cout << 0;
}
