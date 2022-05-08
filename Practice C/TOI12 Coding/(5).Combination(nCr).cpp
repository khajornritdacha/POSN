#include <cstdio>

int n, r, out[20], cnt;
bool visited[20];

void Combination(int len, int old){
    if(len == r){
        cnt++;
        for(int i = 0; i < r; ++i)
            printf("%d ", out[i]);
        printf("\n");
        return;
    }
    else{
        for(int i = old+1; i <= n; ++i){
            if(!visited[i]){
                out[len] = i;
                visited[i] = true;
                Combination(len+1, i);
                visited[i] = false;
            }
        }
    }
    return;
}

int main(){
    printf("Combination nCr\n");
    printf("Enter n, r: ");
    scanf("%d%d", &n, &r);
    printf("----------------------\nCombination...\n");
    Combination(0, 0);
    printf("%dC%d = %d\n", n, r, cnt);
    return 0;
}

