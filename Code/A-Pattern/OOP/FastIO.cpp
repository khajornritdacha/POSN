#include <bits/stdc++.h>
using namespace std;

//Testing fastIO with TOI12 barrier

class fastio{
    public:
        inline fastio& operator >> (int &x){
            x = 0;
            bool neg = false;
            register int c;

            c = getchar_unlocked();
            if(c == '-'){
                neg = true;
                c = getchar_unlocked();
            }
            while('0' <= c and c <= '9'){
                x = (x<<3) + (x<<1) + (c-'0');
                c = getchar_unlocked();
            }

            if(neg) x *= -1;

            return *this;
        }
};

fastio fio;

int main(void){
    int n, W;
    long long ans = 0, sum = 0, len = 0; 
    fio >> n >> W;

    deque<pair<long long, int>> dq;
    dq.emplace_back(0, 0);

    for(int i = 1; i <= n; i++){
        int x; fio >> x;
        sum += x;
        while(!dq.empty() and i-dq.front().second > W) dq.pop_front();

        if(!dq.empty()){
            long long tmp = sum-dq.front().first, cur_len = i-dq.front().second;
            if(tmp > ans){
                ans = tmp;
                len = cur_len;
            } else if(tmp == ans){
                len = min(len, cur_len);
            }
        }

        while(!dq.empty() and sum <= dq.back().first) dq.pop_back();
        dq.emplace_back(sum, i);
    }

    printf("%lld\n%lld\n", ans, len);

    return 0;
}