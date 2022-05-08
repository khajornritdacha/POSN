#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
bitset<1000010> bs;
vector<int> primes,cal[510];
int num[1000010],Q;
void gen(){
    primes.emplace_back(2);
    for(int i=3; i<=1e6; i+=2){
        if(!bs[i]){
            primes.emplace_back(i);
            for(int j=i; j<=1e6; j+=i){
                bs[j] = true;
            }
        }
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    gen();
    num[1] = 1;
    cal[1].emplace_back(1);
    for(int i=2; i<=1e6; i++){
        int k = lower_bound(primes.begin(),primes.end(),i)-primes.begin();
        if(primes[k] == i){
            num[i] = 2;
            cal[2].emplace_back(i);
            continue;
        }
        for(int prime : primes){
            if(i%prime == 0){
                int cnt = 0, tmp = i;
                while(tmp%prime == 0){
                    cnt++;
                    tmp/=prime;
                }
                cnt++;
                num[i] = cnt*num[tmp];
                break;
            }
        }
        cal[num[i]].emplace_back(i);
        //cout << i << " " << num[i] << " " << cal[num[i]].back();
    }
    cin >> Q;
    while(Q--){
        int x,y,d;
        cin >> x >> y >> d;
        if(DEBUG){
            for(int ca : cal[d]){
                cout << ca << " ";
            }
            cout << "\n";
        }
        int k1 = lower_bound(cal[d].begin(),cal[d].end(),x)-cal[d].begin();
        int k2 = upper_bound(cal[d].begin(),cal[d].end(),y)-cal[d].begin();
        cout << k2-k1 << "\n";
    }
}
