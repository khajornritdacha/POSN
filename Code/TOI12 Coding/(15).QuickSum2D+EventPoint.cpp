#include <cstdio>

int A[1005][1005], qSum[1005][1005];
int EventPoint[1005][1005];

int main(){
    int R, C;
    printf("Enter R C: ");
    scanf("%d%d", &R, &C);
    printf("Enter Arr:\n");
    for(int i = 1; i <= R; ++i){
        for(int j = 1; j <= C; ++j){
            scanf("%d", &A[i][j]);
            qSum[i][j] = qSum[i-1][j]+qSum[i][j-1]-qSum[i-1][j-1]+A[i][j];
        }
    }
    printf("---Quick Sum---\n");
    for(int x1 = 1; x1 <= R; ++x1){
        for(int y1 = 1; y1 <= C; ++y1){
            for(int x2 = x1; x2 <= R; ++x2){
                for(int y2 = y1; y2 <= C; ++y2){
                    printf("Sum from (%d,%d) to (%d,%d): %d\n", x1, y1, x2, y2, qSum[x2][y2]-qSum[x1-1][y2]-qSum[x2][y1-1]+qSum[x1-1][y1-1]);
                }
            }
        }
    }
    printf("\n");

    int N;
    printf("====Event Point====\n");
    printf("Enter N: ");
    scanf("%d", &N);
    int maR = 0, maC = 0;
    for(int i = 0; i < N; ++i){
        int x1, y1, x2, y2, v;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &v);
        EventPoint[x1][y1]+=v;
        EventPoint[x1][y2+1]-=v;
        EventPoint[x2+1][y1]-=v;
        EventPoint[x2+1][y2+1]+=v;
        if(x2+1 >= maR)
            maR = x2+1;
        if(y2+1 >= maC)
            maC = y2+1;
    }
    printf("   ");
    for(int i = 1; i <= maC; ++i)
        printf("%2d ", i);
    printf("\n");
    for(int i = 1; i <= maR; ++i){
        printf("%2d ", i);
        for(int j = 1; j <= maC; ++j){
            EventPoint[i][j]+=EventPoint[i-1][j]+EventPoint[i][j-1]-EventPoint[i-1][j-1];
            printf("%2d ", EventPoint[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
3 4
1 2 3 5
-2 -4 -1 2
4 5 6 4
4
1 1 2 3 1
3 2 3 2 15
2 4 2 5 2
2 3 4 6 3
*/

