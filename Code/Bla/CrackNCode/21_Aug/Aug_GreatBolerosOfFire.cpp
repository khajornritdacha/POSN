#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,a[N],tot,wa[10];
///https://www.hackerrank.com/contests/crack-n-code-august-2021/challenges/great-boleros-of-fire
int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        char c; cin >> c;
        a[i] = c-'a';
        //cout << a[i];
    }
    //cout << "\n";
    for(int i=0; i<7; i++){
        cin >> wa[i];
        tot += wa[i];
    }

    //cout << "TOT : " << tot << "\n";

    int l = 0, r = n-tot, ans = -1;
    while(l <= r){
        int mid = (l+r)/2;
        int sz = tot+mid, cnt[10] = {};
        bool ok = false;
        //cout << "Mid : " << mid << " " << sz << "\n";
        for(int i=1; i<=n; i++){
            int chk = 0;
            if(i > sz){
                --cnt[a[i-sz]];
            }
            ++cnt[a[i]];

            /*cout << "Now : " << i << "\n";
            for(int j=0; j<7; j++){
                cout << char(j+'a') << " = " << cnt[j] << "\n";
            }
            cout << "\n";*/
            for(int j=0; j<7; j++)
                chk += (cnt[j] >= wa[j]);
            //cout << chk << "\n";
            if(chk == 7){
                ok = true;
                break;
            }
        }
        if(ok){
            ans = mid, r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
}
