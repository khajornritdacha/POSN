#include<bits/stdc++.h>
using namespace std;

int n,a[10010],wi,uni,mc;

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(a[i] == 10)
            uni++;
        if(a[i] == 13)
            mc++;
        if(a[i-1] == 13 and a[i] == 10)
            wi++;
    }
    cout << wi+1 << " " << uni+1 << " " << mc+1;
}
