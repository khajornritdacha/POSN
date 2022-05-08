#include<bits/stdc++.h>
using namespace std;
int num[1000005],n,b,cnt=1;
main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> b;
    for(int i=3;i<=n;i+=2){
        num[i] = i;
    }
    for(int i=3;i<=n;i+=2){
        if(num[i]!=i)
            continue;
        if(num[i]==i){
            cnt++;
            //cout << i;
            for(int j=i;j<=n;j+=i){
                num[j] = 0;
            }
        }
    }
    if(b>cnt)
        cout << 0;
    else
        cout << cnt-b;
}
