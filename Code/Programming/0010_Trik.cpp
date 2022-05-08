#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
string str;
bool a[5];
main(){
    cin >> str;
    a[1] = true;
    for(int i=0; i<str.size(); i++){
        if(str[i] == 'A')
            swap(a[1], a[2]);
        else if(str[i] == 'B')
            swap(a[2], a[3]);
        else
            swap(a[1], a[3]);
    }
    for(int i=1; i<=3; i++)
        if(a[i])
            cout << i;
}
