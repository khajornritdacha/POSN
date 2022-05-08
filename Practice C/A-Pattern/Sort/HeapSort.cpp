#include<bits/stdc++.h>
using namespace std;

int a[10100],n;
///Time : O(nlogn) Space : O(1)
void Heapify(int sz, int idx){
    int lar = idx;
    int lc = 2*idx;
    int rc = 2*idx+1;
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
void HeapSort(){
    for(int i=n/2; i>=1; i--){
        Heapify(n, i);
    }
    for(int i=n; i>1; i--){
        swap(a[1], a[i]);
        Heapify(i-1, 1);
    }
}

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    HeapSort();

    for(int i=1; i<=n; i++){
        cout << a[i] << " \n"[i==n];
    }
}
