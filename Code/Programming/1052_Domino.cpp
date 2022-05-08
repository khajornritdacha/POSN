#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
const int N = 1e5+10;
int n,x[N],h[N],ra[N],la[N],mx,pos;
char di;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> h[i];
    }
    for(int i=1; i<=n; i++){
        if(ra[i]) continue;
        int r = x[i]+h[i];
        int j = i;
        int cnt = 0;
        while(true){
            j++;
            if(j > n or r <= x[j]){ j--; break;}
            r = max(r, x[j]+h[j]);
        }
        //cout << "I : " << i << " = " << j << "\n";
        for(; j>=i; j--){
            ra[j] = ++cnt;
        }
    }
    for(int i=n; i>=1; i--){
        if(la[i]) continue;
        int r = x[i]-h[i];
        int j = i;
        int cnt = 0;
        while(true){
            j--;
            if(j < 1 or r >= x[j]){ j++; break;}
            r = min(r, x[j]-h[j]);
        }
        for(; j<=i; j++){
            la[j] = ++cnt;
        }
    }
    mx = max(*max_element(ra+1, ra+n+1), *max_element(la+1, la+n+1));
    for(int i=1; i<=n; i++){
        if(mx == ra[i] or mx == la[i]){
            pos = i;
            break;
        }
    }
    if(la[pos] == mx)
        di = 'L';
    else
        di = 'R';
    cout << pos << " " << di << "\n";
    if(DEBUG){
        cout << "MX : " << mx << "\n";
        for(int i=1; i<=n; i++){
            cout << la[i] << " \n"[i==n];
        }
        for(int i=1; i<=n; i++){
            cout << ra[i] << " \n"[i==n];
        }
    }
}
