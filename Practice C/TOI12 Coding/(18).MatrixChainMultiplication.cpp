#include <cstdio>
#include <algorithm>
#define oo 1000000000
using namespace std;

int dp[105][105];
int dimension[205];

int main(){
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    printf("Enter Dimension:\n");
    for(int i = 1; i <= N; ++i){
        printf("Enter R C of Matrix %d: ", i);
        scanf("%d%d", &dimension[i*2-1], &dimension[i*2]);
    }
    /*
    // This Implementation run by diagonal directions of Matrix 2D
    for(int len = 2; len <= N; ++len){
        for(int i = 1; i <= N-len+1; ++i){
            int j = i+len-1;
            int mi = oo;
            for(int k = i; k <= j-1; ++k){
                int cost = dp[i][k] + dp[k+1][j] + (dimension[i*2-1]*dimension[k*2]*dimension[j*2]);
                mi = min(mi, cost);
            }
            dp[i][j] = mi;
        }
    }
    */
    // This Implementation run (left to right) and (bottom to top) in Matrix 2D
    for(int i = N; i >= 1; --i){
        for(int j = i+1; j <= N; ++j){
            int mi = oo;
            for(int k = i; k <= j-1; ++k){
                int cost = dp[i][k] + dp[k+1][j] + (dimension[i*2-1]*dimension[k*2]*dimension[j*2]);
                mi = min(mi, cost);
            }
            dp[i][j] = mi;
        }
    }

    printf("========================================\n");
    printf("Optimal Solution use %d Operations.", dp[1][N]);
    return 0;
}
/*
4
10 20
20 30
30 40
40 30

4
40 20
20 30
30 10
10 30
*/
