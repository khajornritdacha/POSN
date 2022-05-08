#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> vec;
vector<int> ans,prime;
bitset<100010> chk;

void gen(int lv = 0, int now = 1){
    if(lv == vec.size()){
        ans.emplace_back(now);
        return;
    }

    int mul = 1;
    for(int i=0; i<=vec[lv].second; i++){
        gen(lv+1, now*mul);
        mul *= vec[lv].first;
    }
}
main(){
    cin >> n;

    prime.emplace_back(2);
    for(int i=3; i<=1e5; i+=2){
        if(!chk[i]){
            prime.emplace_back(i);
            for(int j=i; j<=1e5; j+=i)
                chk[j] = true;
        }
    }

    int tmp = n;
    for(int p : prime){
        if(tmp % p == 0){
            int cnt = 0;
            while(tmp%p == 0){
                tmp/=p;
                cnt++;
            }
            vec.emplace_back(p, cnt);
        }
    }
    if(tmp != 1)
        vec.emplace_back(tmp, 1);

    gen();

    sort(ans.begin(), ans.end());
    for(int an : ans)
        cout << an << " ";
}
