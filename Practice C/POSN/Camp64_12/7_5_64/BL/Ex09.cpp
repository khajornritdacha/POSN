#include<bits/stdc++.h>
using namespace std;

string str;
char want;

main(){
    cin >> str >> want;
    sort(str.begin(), str.end());
    int l=0, r=(int)str.size()-1, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(str[mid] > want){
            r = mid-1;
        }else if(str[mid] < want){
            l = mid+1;
        }else{
            cout << "Found";
            return 0;
        }
    }
    cout << "Not Found";
}
