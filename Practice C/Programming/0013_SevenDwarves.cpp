#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int sum,a[10],ans[3];
main(){
    for(int i=1; i<=9; i++){
        cin >> a[i];
        sum+=a[i];
    }
    for(int i=1; i<=9; i++){
        for(int j=i+1; j<=9; j++){
            if(sum-a[i]-a[j] == 100){
                ans[1] = i;
                ans[2] = j;
            }
        }
    }
    for(int i=1; i<=9; i++){
        if(ans[1] != i and ans[2] != i)
            cout << a[i] << "\n";
    }
}
