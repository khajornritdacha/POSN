#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e3+10;

long long dp[20][2][200],a[25],b[25];

long long solve(int i, bool b=0, int sum=0){
    if(i < 0) return sum;

    if(dp[i][b][sum] != -1) return dp[i][b][sum];

    long long res = 0, li = (b ? 9 : a[i]);
    for(int j=0; j<=li; j++){
        res += solve(i-1, b|(j != li), sum+j);
    }

    return dp[i][b][sum] = res;
}

void pri(int sz){
    for(int i=0; i<=sz; i++)
        cout << a[i];
    cout << "\n";
}

void test_case(){
    long long tmp1,tmp2,sz=0,resa=0,resb=0;
    cin >> tmp1 >> tmp2;

    if(tmp1 > 0){
        tmp1--;
        while(tmp1){
            a[sz++] = tmp1%10;
            tmp1 /= 10;
        }
        memset(dp, -1, sizeof(dp));
        sz--;
        resa = solve(sz);
    }
    //pri(sz);

    if(tmp2 > 0){
        sz = 0;
        while(tmp2){
            a[sz++] = tmp2%10;
            tmp2 /= 10;
        }
        memset(dp, -1, sizeof(dp));
        sz--;
        resb = solve(sz);
    }
    //pri(sz);

    cout << resb-resa << "\n";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
}
