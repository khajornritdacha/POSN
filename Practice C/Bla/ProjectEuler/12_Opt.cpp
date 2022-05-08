#include <bits/stdc++.h>
using namespace std;

int lim = 1e6+10,D[1000010];
vector<int> prime;

///O(n*sqrt(n))

int Divisor(int num){
    if(D[num] != 0) return D[num];
    int res = 1;
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
    return D[num] = res;
}

int main(void){
    vector<bool> chk(lim+10, false);
    for(int i = 2; i <= lim; i++){
        if(chk[i]) continue;
        prime.push_back(i);
        //cout << i << "\n";
        for(int j = i; j <= lim; j += i) chk[j] = true;
    }
    for(int i = 1; i <= 1000000; i++){
        int res;
        if(i%2){
            res = Divisor(i)*Divisor((i+1)/2);
        }else{
            res = Divisor(i/2)*Divisor(i+1);
        }
        if(res > 1000){
            cout << "ANS :" << i << " " << 1ll*(i+1)*i/2;
            return 0;
        }
    }
    return 0;
}
