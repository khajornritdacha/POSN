#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n,Q,fen[2][N],pw[N],now[N],mod=1e9+7;


void up(int idx, int val, int cd){
    if(idx == 0) return;
    while(idx <= n){
        fen[cd][idx] += val;
        fen[cd][idx] %= mod;
        fen[cd][idx] += mod;
        fen[cd][idx] %= mod;
        idx += idx&-idx;
    }
}

int qs(int idx, int cd){
    if(idx == 0) return 0;
    int res = 0;
    while(idx){
        res += fen[cd][idx];
        res %= mod;
        res += mod;
        res %= mod;
        idx -= idx&-idx;
    }
    return res;
}

int inv(int b, int p){
    if(p == 0) return 1;
    if(p == 1) return b;
    int tmp = inv(b, p/2);
    tmp = (tmp*tmp)%mod;
    if(p%2)
        tmp *= b;
    return tmp%mod;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    pw[0] = 1;
    for(int i=1; i<=n; i++){
        pw[i] = pw[i-1]*31;
        pw[i] %= mod;
    }
    for(int i=1; i<=n; i++){
        char tmp; cin >> tmp;
        now[i] = tmp-'a'+1;
        up(i, (now[i]*pw[i])%mod, 0);
        up(n-i+1, (now[i]*pw[n-i+1])%mod, 1);
    }
    /*
    for(int i=1; i<=n; i++){
        cout << "I : " << i << " = " << qs(i, 0) << " " << qs(i, 1) << "\n";
    }
    cout << "------------\n";*/

    for(int i=1; i<=Q; i++){
        int code;
        cin >> code;
        if(code == 1){
            int pos;
            char tmp;
            cin >> pos >> tmp;
            up(pos, -1*((now[pos]*pw[pos])%mod), 0);
            up(n-pos+1, -1*((now[pos]*pw[n-pos+1])%mod), 1);
            now[pos] = tmp-'a'+1;
            up(pos, (now[pos]*pw[pos])%mod, 0);
            up(n-pos+1, (now[pos]*pw[n-pos+1])%mod, 1);
        }else{
            int l,r; cin >> l >> r;
            int h1 = (((qs(r, 0)-qs(l-1, 0))%mod+mod)%mod)*inv(pw[l], mod-2);
            int h2 = (((qs(n-l+1, 1)-qs(n-r, 1))%mod+mod)%mod)*inv(pw[n-r+1], mod-2);
            h1 %= mod, h2 %= mod;
            //cout << "L&R : " << l << " " << r << "\n";
            //cout << n-l+1 << " " << n-r << "\n";
            if(h1 == h2){
                cout << "YES";
            }else{
                cout << "NO";
            }
            cout << "\n";
        }

        /*cout << "NOW : ";
        for(int i=1; i<=n; i++){
            cout << char(now[i]+'a'-1) << " ";
        }
        cout << "\n";*/
    }
}
