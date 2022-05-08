#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int a[N],n,P1,P2;

void Heapify(int sz, int idx){
    int lar = idx;
    int lc = idx*2;
    int rc = idx*2+1;
    if(lc <= sz and a[lc] > a[lar]){
        lar = lc;
    }
    if(rc <= sz and a[rc] > a[lar]){
        lar = rc;
    }
    if(lar != idx){
        swap(a[lar], a[idx]);
        Heapify(sz, lar);
    }
}
void Heapsort(){
    for(int i=n; i>=1; i--){
        Heapify(n, i);
    }
    for(int i=n; i>=1; i--){
        swap(a[i], a[1]);
        Heapify(i-1, 1);
    }
}

main(){
    cin >> P1 >> P2 >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    Heapsort();

    /*for(int i=1; i<=n; i++){
        cout << a[i] << " \n"[i==n];
    }*/

    int res1 = P1*(n+1)/100;
    int res2 = P2*(n+1)/100;

    cout << res1 << " " << a[res1] << " " << res2 << " " << a[res2] << " " << a[res1]-a[res2] << "\n";
}
