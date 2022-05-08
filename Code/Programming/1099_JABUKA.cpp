#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
const int N = 1e2+10;
long long R,G,tot;
bitset<1000100> chk;
vector<int> fac,prime;
vector<pair<int,int>> vec;
void gen2(int lv=0, int now = 1){
    if(lv == vec.size()){
        fac.emplace_back(now);
        return;
    }
    int tmp = 1;
    for(int i=0; i<=vec[lv].second; i++){
        gen2(lv+1, now*tmp);
        tmp*=vec[lv].first;
    }
}
void gen(){
    prime.emplace_back(2);
    for(int i=3; i<=1e5; i+=2){
        if(!chk[i]){
            prime.emplace_back(i);
            for(int j=i; j<=1e5; j+=i)
                chk[j]=true;
        }
    }
}
main(){
    gen();
    cin >> R >> G;
    tot = __gcd(R,G);
    for(int p : prime){
        if(tot%p == 0){
            int cnt = 0;
            while(tot%p == 0){
                tot/=p;
                cnt++;
            }
            vec.emplace_back(p, cnt);
        }
    }
    if(tot!=1)
        vec.emplace_back(tot, 1);
    gen2();
    sort(fac.begin(), fac.end());
    for(int f : fac)
        cout << f << " " << R/f << " " << G/f << "\n";
}
