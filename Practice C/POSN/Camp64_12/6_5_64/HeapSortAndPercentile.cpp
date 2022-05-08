#include<bits/stdc++.h>
using namespace std;

int a[1010],P,n;

void heapify(int sz, int idx){
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
        heapify(sz, lar);
    }
}
void HeapSort(){
    for(int i=n/2; i>=1; i--){
        heapify(n, i);
    }
    /*for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";*/
    for(int i=n; i>1; i--){
        swap(a[1], a[i]);
        heapify(i-1, 1);
    }
}
main(){
    cin >> P >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    HeapSort();

    /*for(int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";*/

    int Per = (P)*(n+1)/100;

    cout << Per << " " << a[Per] << "\n";
}
