#include <cstdio>

int n, r, out[20], cnt;
bool visited[20];

void Permutation(int len){
    if(len == r){
        cnt++;
        for(int i = 0; i < r; ++i)
            printf("%d ", out[i]);
        printf("\n");
        return;
    }
    else{
        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                out[len] = i;
                visited[i] = true;
                Permutation(len+1);
                visited[i] = false;
            }
        }
    }
    return;
}

int main(){
    printf("Permutation nPr\n");
    printf("Enter n, r: ");
    scanf("%d%d", &n, &r);
    printf("----------------------\nPermutation...\n");
    Permutation(0);
    printf("%dP%d = %d\n", n, r, cnt);
    return 0;
}
