#include<bits/stdc++.h>
using namespace std;
long long a[15],b,ans=1;
int n;
bool visit[1000005];
unordered_map<long long,long long> um;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> a[0];
    b = a[0];
    for(int i=1;i<n;i++){
        cin >> a[i];
        b = __gcd(a[i],b);
    }
    //cout << b;
    while(1){
        if(b/2*2!=b){
            break;
        }
        b/=2;
        um[2]++;
    }
    //cout << um[2] << " " << b;
    for(int i=3;i<=1e6;i+=2){
        while(1){
            if(b/i*i!=b){
                break;
            }
            b/=i;
            um[i]++;
        }
        if(!visit[i]){
            for(int j=i*2;j<=1e6;j+=i){
                visit[j] = true;
            }
        }
    }
    for(auto x:um){
        ans *= (x.second+1);
        //cout << x.first << " " << x.second << "\n";
    }
    cout << ans;
}
