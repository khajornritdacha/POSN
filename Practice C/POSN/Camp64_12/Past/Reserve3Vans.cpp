#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n;
main(){
    cin >> n;
    int a,b,c;
    a = b = c =1;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(a <= b and a <= c){
            cout << "A";
            a+=x;
        }else if(b <= c){
            cout << "B";
            b+=x;
        }else{
            cout << "C";
            c+=x;
        }
        cout << "\n";
    }
}
