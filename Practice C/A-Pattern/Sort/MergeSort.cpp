#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

int a[1000],n;

void Mergesort(int l, int r){
    if(l >= r)
        return;

    int mid = (l+r)/2;

    Mergesort(l, mid);
    Mergesort(mid+1, r);

    if(DEBUG){
        cout << "L&R : " << l << " " << r << " " << mid << "\n";
        for(int i=1; i<=n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    int sl = mid-l+1, sr = r-mid;
    int le[sl+2], ri[sr+2];

    for(int j=1,i=l; i<=mid; i++, j++)
        le[j] = a[i];
    for(int j=1, i=mid+1; i<=r; i++, j++)
        ri[j] = a[i];

    if(DEBUG){
        cout << "LE : " ;
        for(int j=1; j<=sl; j++){
            cout << le[j] << " \n"[j == sl];
        }
        cout << "RI : " ;
        for(int j=1; j<=sr; j++){
            cout << ri[j] << " \n"[j==sr];
        }
    }

    int p1=1, p2=1, k=l;
    while(p1 <= sl and p2 <= sr){
        if(le[p1] < ri[p2]){
            a[k] = le[p1++];
        }else{
            a[k] = ri[p2++];
        }
        k++;
    }

    while(p1 <= sl){
        a[k] = le[p1++];
        k++;
    }

    while(p2 <= sr){
        a[k] = ri[p2++];
        k++;
    }
}
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    Mergesort(1, n);
    for(int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
}
