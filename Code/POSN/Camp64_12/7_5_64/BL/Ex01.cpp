#include<bits/stdc++.h>
using namespace std;

int a[15],p1,p2,sum,dif,d1,d2;

main(){
    cout << "Input 10 Digit Numbers :\n";
    for(int i=1; i<=10; i++){
        cin >> a[i];
    }
    for(int i=1; i<=10; i++){
        for(int j=i+1; j<=10; j++){
            if(a[i]+a[j] > sum){
                sum = a[i]+a[j];
                p1 = i;
                p2 = j;
            }
            if(abs(a[i]-a[j]) > dif){
                dif = abs(a[i]-a[j]);
                d1 = i;
                d2 = j;
            }
        }
    }
    cout << "Maximum Sum is ("<<a[p1]<<","<<a[p2]<<") = "<<sum<<"\n";
    cout << "Maximum Diff is ("<<a[d1]<<","<<a[d2]<<") = "<<dif<<"\n";
}
