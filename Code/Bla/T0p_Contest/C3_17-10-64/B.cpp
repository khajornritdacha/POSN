#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void test_case(){
    ll n;
    int cnt[15] = {};
    cin >> n;
    if(n == 0){ cout << "10\n"; return;}
    else if(n == 1){ cout << "1\n"; return;}

    ll tmp = n;
    for(int fa : {2, 3, 5, 7}){
        while(tmp % fa == 0){
            tmp /= fa;
            cnt[fa]++;
        }
    }
    if(tmp != 1){ cout << "-1\n"; return;}

    if(cnt[2] >= 3){
        int ti = cnt[2]/3;
        cnt[8] += ti;
        cnt[2] -= ti*3;
    }
    if(cnt[3] >= 2){
        int ti = cnt[3]/2;
        cnt[9] += ti;
        cnt[3] -= ti*2;
    }
    if(cnt[2] >= 1 and cnt[3] >= 1){
        int ti = min(cnt[2], cnt[3]);
        cnt[6] += ti;
        cnt[2] -= ti, cnt[3] -= ti;
    }
    if(cnt[2] >= 2){
        int ti = cnt[2]/2;
        cnt[4] += ti;
        cnt[2] -= ti*2;
    }

    for(int i = 1; i <= 9; i++){
        while(cnt[i]){
            cout << i;
            cnt[i]--;
        }
    }
    cout << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
