#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,g,ans=1;
vector<int> prime;
bool chk[101000];
main(){
    prime.emplace_back(2);
    for(int i=3; i<=1e5; i+=2){
        if(!chk[i]){
            prime.emplace_back(i);
            for(int j=i; j<=1e5; j+=i){
                chk[j] = true;
            }
        }
    }
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        g = __gcd(x, g);
    }
    for(int p : prime){
        if(p > g) break;
        if(g%p == 0){
            int cnt = 0;
            while(g%p == 0){
                cnt++;
                g/=p;
            }
            ans*=(cnt+1);
        }
    }
    if(g != 1)
        ans*=2;
    cout << ans;
}
