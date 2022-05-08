#include<bits/stdc++.h>
using namespace std;
int n,num,visit[10010],dp[10010],sum[10010],t=1;
int solve(int i){
    if(i==0) return 0;
    if(visit[i]) return dp[i];
    visit[i]=true;
    int temp=1e9;
    for(int k=1; k*k<=10000; k++){
        if(sum[k]>i) break;
        temp=min(temp,solve(i-sum[k])+1);
    }
    return dp[i]=temp;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=1; i*i<=10000; i++){
        sum[i]=i*i;
    }
    cin >> n;
    while(t++<=n){
        cin >> num;
        if(!visit[num]) solve(num);
        cout << dp[num] << "\n";
    }
}

