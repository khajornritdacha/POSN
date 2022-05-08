#include <cstdio>
#include <cstring>
// This algorithm use to count
// string matching in O(N+M)

char T[100005], P[100005]; // T = Text, P = Pattern
int b[100005], N, M;    // b = back table
// back table tell we that if we mismatch in P[i]
// we have to make idx back to b[i]

void kmpPreProcess(){
    int i = 0, idx = -1;    // Starting Values
    b[0] = -1;
    while(i < M){     // Pre-Process the pattern string P
        while(idx >= 0 && P[i] != P[idx])   //different, reset idx using b
            idx = b[idx];
        i++; idx++;     // if same, advance both pointers
        b[i] = idx;     // if we false matching in index "i" we have to back to index "idx"
    }
    ///PRINT-ZONE///
    printf("\n");
    printf("IDX:    ");
    for(int i = 0; i < M; ++i)
        printf(" %2d", i);
    printf("\n");
    printf("Pattern:");
    for(int i = 0; i < M; ++i)
        printf("  %c", P[i]);
    printf("\n");
    printf("BackArr: ");
    for(int i = 0; i < M; ++i){
        if(b[i] == -1)
            printf("%d", b[i]);
        else
            printf(" %2d", b[i]);
    }
    printf("\n");
}

void kmpSearch(){   // This is similar as kmpPreProcess(), but on string T
    int i = 0, idx = 0, cnt = 0;
    while(i < N){
        while(idx >= 0 && T[i] != P[idx])   // We mismatch P[idx] with T[i]
            idx = b[idx];        // Then idx will back to b[idx]
        i++; idx++;
        if(idx == M){
            cnt++;
            printf("P is found at index %d in T\n", i-M);
            idx = b[idx];
        }
    }
    printf("We found %d string(s) that matching in Text\n", cnt);
}

int main(){
    printf("Enter Text: ");
    scanf("%s", T);
    printf("Enter Pattern: ");
    scanf("%s", P);
    N = strlen(T);
    M = strlen(P);
    kmpPreProcess();
    printf("====================================================\n");
    kmpSearch();
    return 0;
}
/*
IDONOTLIKESEVENTYSEVBUTSEVENTYSEVENTYSEVEN
SEVENTYSEVEN
*/
