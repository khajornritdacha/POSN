#include<bits/stdc++.h>
using namespace std;
int C,num,cost[15],mx,a[110];
main(){
    cin >> C;
    for(int i=1; i<=9; i++){
        cin >> cost[i];
        if(C/cost[i] > mx){
            mx = C/cost[i];
            num = i;
        }else if(C/cost[i] == mx){
            if(cost[num] > cost[i]){
                num = i;
            }else if(cost[num] == cost[i]){
                num = max(num, i);
            }
        }
    }
    C-=cost[num]*mx;
    for(int i=mx; i>=1; i--){
        a[i] = num;
        for(int j=9; j>=num+1; j--){
            if(C+cost[a[i]]-cost[j] >= 0){
                C+=cost[a[i]]-cost[j];
                a[i] = j;
                break;
            }
        }
    }
    for(int i=mx; i>=1; i--)
        cout << a[i];
}
