#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
using ll = long long;

int qs[N],num[N],a[N];

///https://www.spoj.com/problems/NOTATRI/

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true){
        int n; cin >> n;
        if(n == 0) return 0;

        map<int,int> mp;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }

        int idx = 1;
        for(auto [val, cnt] : mp){
            num[idx] = val;
            qs[idx] = qs[idx-1]+cnt;
            idx++;
        }

        ll sum = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                int k = upper_bound(num+1, num+idx, a[i]+a[j])-num;
                //cout << a[i]+a[j] << " " << k << "\n";
                sum += n-qs[k-1];
            }
            //cout << "\n";
        }
        sum /= 2;
        cout << sum << "\n";
    }
    return 0;
}
