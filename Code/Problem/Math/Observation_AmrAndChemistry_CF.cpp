#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

const int N = 4e5+10, lim = 4e5;
using ll = long long;

///https://vjudge.net/contest/466980#problem/F
/// 6 Nov 2021

int n,a[N],b[N];
bool chk[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }

    ///find maximum number that every element can be divided into
    bool con = true;
    int mn = 1e9, ans = 0;
    do{
        con = false;
        int cur = 1e9;
        for(int i = 1; i <= n; i++){
            cur = min(cur, b[i]);
        }

        for(int i = 1; i <= n; i++){
            while(b[i] > cur){
                b[i] /= 2;
                ans++;
            }
            if(b[i] != cur) con = true;
        }
        mn = cur;
    }while(con);

    if(DEBUG){
        cout << "MN : " << mn << " " << ans << "\n";
    }

    for(int i = 1; i <= lim; i *= 2) chk[i] = true; ///check if x is power of 2


    for(int want = mn; want <= lim; want *= 2){
        int cnt = 0;
        if(DEBUG){
            cout << "------------------\n";
            cout << "WANT : " << want << "\n";
        }
        for(int i = 1; i <= n; i++){ ///Count how many times to change every element into want
            int tmp = a[i];
            while(tmp > 1 and (want % tmp != 0 or !chk[want/tmp])){
                tmp /= 2, cnt++;
            }

            if(DEBUG){
                cout << "I : " << i << " = " << tmp << " " << cnt << "\n";
            }

            while(tmp < want){
                tmp *= 2, cnt++;
            }
            assert(tmp == want);
        }
        ans = min(ans, cnt);
        if(DEBUG){
            cout << "CNT : " << cnt << "\n";
            cout << "------------------\n";
        }
    }


    cout << ans << "\n";

    return 0;
}
