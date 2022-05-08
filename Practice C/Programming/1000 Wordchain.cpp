#include<bits/stdc++.h>
using namespace std;
int l,n,cou;
string temp,str;
main(){
    cin >> l >> n;
    if(n==1){
        cin >> str;
        cout << str;
    return 0;
}
    for(int i=0;i<n;i++){
        temp = str;
        cou=0;
        cin >> str;
        if(i==0)
            continue;
        for(int j=0;j<l;j++){
            if(temp[j]!=str[j])
                cou++;
            if(cou>2){
            cout << temp;
            return 0;
        }
        }
    }
    cout << str;
return 0;}
