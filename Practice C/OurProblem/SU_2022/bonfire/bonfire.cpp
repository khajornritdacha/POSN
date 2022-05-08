#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n,a,b,c,ans;
long long dp[51][51][51][3][3];

int main(){
	scanf("%d%d%d%d",&n,&a,&b,&c);
	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			for(int k=0;k<=c;k++){
				if(i == 0 && j == 0 && k == 0) continue;
				else if(i == 1 && j == 0 && k == 0) dp[i][j][k][0][0] = 1;
				else if(i == 0 && j == 1 && k == 0) dp[i][j][k][1][1] = 1;
				else if(i == 0 && j == 0 && k == 1) dp[i][j][k][2][2] = 1;
				else{
					for(int l=0;l<=2;l++){
						if(i){
							dp[i][j][k][l][0] += dp[i-1][j][k][l][1] + dp[i-1][j][k][l][2];
							dp[i][j][k][l][0] %= mod;
						}
						if(j){
							dp[i][j][k][l][1] += dp[i][j-1][k][l][0] + dp[i][j-1][k][l][2];
							dp[i][j][k][l][1] %= mod;
						}
						if(k){
							dp[i][j][k][l][2] += dp[i][j][k-1][l][0] + dp[i][j][k-1][l][1];
							dp[i][j][k][l][2] %= mod;
						}
					}
				}
			}
		}
	}
	
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			if(i!=j){
				ans += dp[a][b][c][i][j];	
				ans %= mod;
			}
		}
	}
	
	printf("%d",ans);
}
