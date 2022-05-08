#include <bits/stdc++.h>
using namespace std;

int lim = 1e6+10;
///O(n^2)
int main(void){
    vector<int> prime;
    vector<bool> chk(lim+10, false);
    for(int i = 2; i <= lim; i++){
        if(chk[i]) continue;
        prime.push_back(i);
        //cout << i << "\n";
        for(int j = i; j <= lim; j += i) chk[j] = true;
    }
    for(int i = 1; i <= 1000000; i++){
        long long num = 1ll*(i+1)*i/2,res = 1;
        for(int p : prime){
            if(p > num) break;
            int cnt = 0;
            while(num%p == 0){
                num /= p;
                cnt++;
            }
            res *= (cnt+1);
        }
        if(num > 1) res *= 2;
        //cout << i << " " << res << "\n";
        if(res > 1000){
            cout << "ANS :" << i << " " << 1ll*(i+1)*i/2;
            return 0;
        }
    }
    return 0;
}
