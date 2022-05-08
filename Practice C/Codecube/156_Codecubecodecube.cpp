#include<bits/stdc++.h>
using namespace std;

string str,pt="codecube";
int ans;

main(){
    cin >> str;
    int j=0;
    for(int i=0; i<str.size(); i++){
        while(str[i] != pt[j]){
            ans++;
            //cout << pt[j] << "\n";
            j++;
            j%=pt.size();
        }
        j++;
        j%=pt.size();
        //cout << "I : " << i << " =  "<< j << " " << pt[j] << "\n";
    }
    if(j!=0)
        ans+=(int)pt.size()-j;
    cout << ans;
}
