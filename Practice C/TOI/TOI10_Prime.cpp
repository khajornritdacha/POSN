#include<bits/stdc++.h>
using namespace std;
int visit[7368788],n,cnt=1;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    if(n==1){
        cout << 2;
    }else{
    for(int i=3;i<=7368787;i+=2){
        if(!visit[i]){
            cnt++;
            if(cnt==n){
                cout << i;
                return 0;
            }
            for(int j=i*2;j<=7368787;j+=i){
                visit[j] = 1;
            }
        }
    }
    }
}
