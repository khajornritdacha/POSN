#include <cstdio>

int A[100005], tmp[100005], inversion;

void MergeSort(int L, int R){
    if(L == R)
        return;
    int mid = (L+R)/2;
    MergeSort(L, mid);
    MergeSort(mid+1, R);
    int i = L, j = mid+1, idx = L;
    while(i <= mid && j <= R){
        if(A[i] <= A[j])
            tmp[idx++] = A[i++];
        else if(A[i] > A[j]){
            inversion+=(mid-i+1);
            tmp[idx++] = A[j++];
        }
    }
    while(i <= mid)
        tmp[idx++] = A[i++];
    while(j <= R)
        tmp[idx++] = A[j++];
    for(int i = L; i <= R; ++i)
        A[i] = tmp[i];
    return;
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &A[i]);
    MergeSort(0, N-1);
    printf("Inversion: %d\n", inversion);
    return 0;
}
