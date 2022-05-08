#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
string a,b,op;
main(){
    cin >> a >> op >> b;
    if(op == "*"){
        cout << "1";
        for(int i=0; i<sz(a)+sz(b)-2; i++)
            cout << "0";
    }else{
        if(sz(a) < sz(b))
            swap(a, b);
        if(sz(a) != sz(b)){
            cout << "1";
            for(int i=1; i<sz(a); i++)
                if(i == sz(a)-sz(b))
                    cout << "1";
                else
                    cout << "0";
        }else{
            cout << "2";
            for(int i=0; i<sz(a)-1; i++)
                cout << "0";
        }
    }
}
