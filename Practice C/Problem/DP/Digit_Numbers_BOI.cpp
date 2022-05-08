//Task : BOI 13 Numbers

#include <bits/stdc++.h>
using namespace std;

long long dp[25][15][15][2][2];
bool vi[25][15][15][2][2];

//Digit DP
//p1 is the previous number
//p2 is the number previous p1
//lz means there currently is leading zeros

long long solve(int i, int p1, int p2, bool b, bool lz, const string &str){
    if(i == str.size()){
        return dp[i][p1][p2][b][lz] = 1;
    }

    if(vi[i][p1][p2][b][lz]) return dp[i][p1][p2][b][lz];
    vi[i][p1][p2][b][lz] = true;

    int ub;
    if(b) ub = 9;
    else ub = str[i]-'0';

    for(int j = 0; j <= ub; j++){
        if(lz){
            dp[i][p1][p2][b][lz] += solve(i+1, (j==0) ? 10 : j, 10, b|(j!=ub), lz&(j==0), str);
        } else {
            if(j == p1 or j == p2) continue;
            dp[i][p1][p2][b][lz] += solve(i+1, j, p1, b|(j!=ub), 0, str);
        }
    }

    return dp[i][p1][p2][b][lz];
}

long long cal(long long val){
    if(val < 0) return 0; //in case a = 0
    long long tmp = val;
    string str = "";
    while(tmp){
        str.push_back(tmp%10 + '0');
        tmp /= 10;
    }
    reverse(str.begin(), str.end()); //turn number into string

    memset(dp, 0, sizeof(dp));
    memset(vi, 0, sizeof(vi));

    solve(0, 10, 10, 0, 1, str); //10 means no number

    return dp[0][10][10][0][1];
}

int main(void){
    long long a, b; cin >> a >> b;

    cout << cal(b)-cal(a-1) << "\n";

    return 0;
}