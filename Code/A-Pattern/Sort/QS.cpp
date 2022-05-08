#include<bits/stdc++.h>
using namespace std;

int a[1000],n;

void qs(int l, int r){
    if(l >= r)
        return;
    int i=l;
    for(int j=l; j<r; j++){
        if(a[j] < a[r]){
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    qs(l, i-1);
    qs(i+1, r);
}
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    qs(1, n);
    for(int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
}
