#include<bits/stdc++.h>
using namespace std;
int a[5];
main(){
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    int sz = a[0]*a[1]*a[2];
    if(a[0]<=8 and a[1]<=10 and a[2]<=15){
        cout << "1\n" << 8*10*15-sz;
    }else if(a[0]<=12 and a[1]<=15 and a[2]<=25){
        cout << "2\n" << 12*15*25-sz;
    }else if(a[0]<=20 and a[1]<=40 and a[2]<=50){
        cout << "3\n" << 20*40*50-sz;
    }else{
        cout << "Oversize product\n" << sz-20*40*50;
    }
}
