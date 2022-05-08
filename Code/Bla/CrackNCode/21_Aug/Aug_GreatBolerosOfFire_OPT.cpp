#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,a[N],tot,wa[10];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        char c; cin >> c;
        a[i] = c-'a';
        //cout << a[i];
    }
    //cout << "\n";
    int st = 0;
    for(int i=0; i<7; i++){
        cin >> wa[i];
        tot += wa[i];
        if(wa[i] == 0)
            st++;
    }

    //cout << "TOT : " << tot << "\n";

    int l = 0, r = n-tot, ans = -1;
    while(l <= r){
        int mid = (l+r)/2, chk = st;
        int sz = tot+mid, cnt[10] = {};
        bool ok = false;
        //cout << "Mid : " << mid << " " << sz << "\n";
        for(int i=1; i<=n; i++){
            if(i > sz){
                if(cnt[a[i-sz]] == wa[a[i-sz]])
                    chk--;
                --cnt[a[i-sz]];
            }

            if(++cnt[a[i]] == wa[a[i]])
                chk++;

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
