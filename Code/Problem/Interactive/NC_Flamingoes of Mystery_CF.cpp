#include<bits/stdc++.h>
using namespace std;

///https://codeforces.com/problemset/problem/1425/F
int ask(int l, int r){
    cout << "? " << l << " " << r << endl;
    int x;
    cin >> x;
    return x;
}

main(){
    int n,a[1010]={};
    cin >> n;
    int x = ask(1, 3);
    int y = ask(1, 2);
    a[3] = x-y;
    int z = ask(2, 3);
    a[2] = z-a[3];
    a[1] = y-a[2];

    for(int i=4; i<=n; i++){
        int tmp = ask(i-1, i);
        a[i] = tmp-a[i-1];
    }

    cout << "! ";
    for(int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
