#include<bits/stdc++.h>
using namespace std;
bool change = true;
int a[10];
main(){
    cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
    while(change){
        change = false;
        for(int i=1; i<=4; i++){
            if(a[i] > a[i+1]){
                swap(a[i], a[i+1]);
                change = true;
                for(int i=1; i<=5; i++)
                    cout << a[i] << " \n"[i==5];
            }
        }
    }
}
