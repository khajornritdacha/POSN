#include<bits/stdc++.h>
using namespace std;
int a[5];
char c[5];

main(){
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    cin >> c;
    for(int i=0; i<3; i++)
        cout << a[c[i]-'A'] << " ";
}
