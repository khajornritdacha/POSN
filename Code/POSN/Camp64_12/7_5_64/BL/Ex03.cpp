#include<bits/stdc++.h>
using namespace std;

int a[15],as[15],de[15];

main(){
    cout << "Input 10 Digit Numbers :\n";
    for(int i=1; i<=10; i++){
        cin >> a[i];
        as[i] = a[i];
        de[i] = a[i];
    }
    sort(as+1, as+10+1);
    sort(de+1, de+10+1, greater<int>());
    int pos;
    cout << "Input n : ";
    cin >> pos;
    cout << "Minimum Order#";
    if(pos!=10)
        cout << "0" << pos;
    else
        cout << "10";
    cout << " is " << as[pos] << "\n";
    cout << "Maximum Order#";
    if(pos!=10)
        cout << "0" << pos;
    else
        cout << "10";
    cout << " is " << de[pos] << "\n";
}
