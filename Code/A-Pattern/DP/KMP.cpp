#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long OG,temp,con=1;
string s,l;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> l;
    for(int i=0;i<s.size();i++){
        OG = OG*31+s[i];
        con*=31;
    }
    for(int i=0;i<l.size();i++){
        temp = temp*31+l[i];
        if(i>=s.size()){
            temp-=l[i-s.size()]*con;
        }
        if(temp==OG){
            cout << "YAY\n";
            return 0;
        }
    }
    cout << "NOOOOOOOOO\n";
    return 0;
}
