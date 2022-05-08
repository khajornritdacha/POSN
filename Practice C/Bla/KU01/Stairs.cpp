#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+10, K = 1e5+10;
using ll = long long;
ll n,a[N],epr[K],epb[K],qsb[K],qsr[K];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 2; i <= n; i++){
        int l = min(a[i], a[i-1]), r = max(a[i], a[i-1]);
        l++, r--;
        if(l > r) continue;
        if(l%2){
            epb[l]++;
            epr[l+1]++;
        }else{
            epb[l+1]++;
            epr[l]++;
        }
        if(r%2){
            epb[r+2]--;
            epr[r+1]--;
        }else{
            epb[r+1]--;
            epr[r+2]--;
        }
    }
    for(int i = 2; i <= 1e5; i++){
        if(i%2){
            epb[i] += epb[i-2];
        }else{
            epr[i] += epr[i-2];
        }
    }
    for(int i = 1; i <= 1e5; i++){
        qsb[i] = qsb[i-1]+epb[i];
        qsr[i] = qsr[i-1]+epr[i];
    }
    int Q; cin >> Q;
    while(Q--){
        int l,r; cin >> l >> r;
        if(l > 0) l--;
        cout << qsr[r]-qsr[l] << " " << qsb[r]-qsb[l] << "\n";
    }
    return 0;
}
