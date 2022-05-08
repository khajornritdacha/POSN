#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int x,sum,ans;
main(){
    cin >> x;
    for(int i=1; i<=7; i++){
        int y;
        cin >> y;
        sum += y;
    }
    int tmp = sum;
    if(sum > 250){
        ans += (sum-250)*60;
        sum = 250;
    }
    if(sum > 100){
        ans += (sum-100)*70;
        sum = 100;
    }
    ans += sum*80;
    cout << ans << "\n" << tmp*x << "\n";
    if(tmp*x - ans > 0)
        cout << tmp*x-ans;
    else
        cout << "No Profit";
}
