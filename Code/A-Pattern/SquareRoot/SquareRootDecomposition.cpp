#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e5+10;
int n,BS,a[N],b[N],Q;

///BS = (int)sqrt(n+.0)+1

int ask(int l, int r){
    int cl = l/BS, cr = r/BS, res = 0;

    if(cl == cr){
        for(int i=l; i<=r; i++)
            res += a[i];
    }else{
        for(int i=l, ed=(cl+1)*BS-1; i<=ed; i++)
            res += a[i];
        for(int i=cl+1; i<=cr-1; i++)
            res += b[i];
        for(int i=cr*BS; i<=r; i++)
            res += a[i];
    }
    return res;
}

void up(int idx, int val){
    a[idx] = val;
    int bi = idx/BS;
    b[bi] = 0; ///reset representative
    for(int i=bi*BS, ed=(bi+1)*BS-1; i<=ed; i++){
        b[bi] = max(b[bi], a[i]);
    }
    return;
}

main(){
    cin >> n;
    BS = (int)sqrt(n+.0)+1;

    for(int i=0; i<n; i++){
        cin >> a[i];
        b[i/BS] += a[i];
    }

    if(DEBUG){
        cout << "BS : " << BS << "\n";
        for(int i=0; i<=n/BS; i++){
            cout << b[i] << " ";
        }
        cout << "\n";
        cout << "----------------\n";
    }

    cin >> Q;
    for(int i=1; i<=Q; i++){
        int l,r; cin >> l >> r;
        cout << ask(l, r) << "\n";
        up(3, 10);
    }
}

/*
8
1 2 5 3 10 2 8 3
4
0 7
0 3
4 5
2 7
*/
