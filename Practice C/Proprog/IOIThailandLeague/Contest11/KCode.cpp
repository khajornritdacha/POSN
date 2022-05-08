#include<bits/stdc++.h>
#define le(x) (int)(x).size()
using namespace std;

string str,pat = "UUDDLRLRBAS";
int mx;

main(){
    cin >> str;
    for(int sz = le(pat)-1; sz>=0; sz--){
        int cnt = 0;
        //cout << "SZ : " << sz << " = ";
        for(int i=0; i<sz; i++){
            //cout << le(str)-sz+i << " " << str[le(str)-sz+1+i] << " " << pat[i] << "\n";
            if(le(str)-sz+i < 0)
                break;
            if(str[le(str)-sz+i] != pat[i])
                break;
            cnt++;
        }
        //cout << "\n";
        if(cnt == sz){
            mx = max(mx, cnt);
            break;
        }
    }
    cout << pat.substr(mx, le(pat)-mx);
}
