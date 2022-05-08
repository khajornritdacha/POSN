#include <cstdio>

int A[1005], qSum[1005];
int EventPoint[100005];

int main(){
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    printf("Enter Arr: ");
    for(int i = 1; i <= N; ++i){
        scanf("%d", &A[i]);
        qSum[i] = qSum[i-1]+A[i];
    }
    printf("---Quick Sum---\n");
    for(int i = 1; i <= N; ++i){
        printf("---------------\n", i);
        for(int j = i; j <= N; ++j)
            printf("Sum from %d to %d: %d\n", i, j, qSum[j]-qSum[i-1]);
    }
    printf("\n");

    printf("====Event Point====\n");
    printf("Enter N: ");
    scanf("%d", &N);
    int ma = 0;
    for(int i = 0; i < N; ++i){
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        EventPoint[x]+=v;
        EventPoint[y+1]-=v;
        if(y+1 > ma)
            ma = y+1;
    }
    printf("IDX:  ");
    for(int i = 1; i <= ma; ++i)
        printf("%2d ", i);
    printf("\n");
    printf("QSUM: ");
    for(int i = 1; i <= ma; ++i){
        EventPoint[i]+=EventPoint[i-1];
        printf("%2d ", EventPoint[i]);
    }
    return 0;
}
/*
10
-1 2 -5 2 13 5 6 7 9 10
5
1 6 1
2 3 1
3 3 5
7 9 10
6 7 2
*/
