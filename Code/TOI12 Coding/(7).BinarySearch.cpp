#include <cstdio>

int A[] = {1, 2, 3, 3, 3, 3, 4, 5, 99, 100, 100}, N = 11;

int BS_FirstOneThatMoreThanOrEqualTo(int fnd){
    int L = 0, R = N-1, ans = -1, mid;
    while(L <= R){
        mid = (L+R)/2;
        if(A[mid] >= fnd){
            ans = mid;
            R = mid-1;
        }
        else if(A[mid] < fnd){
            L = mid+1;
        }
    }
    return ans;
}

int BS_FirstOneThatEqualTo(int fnd){
    int L = 0, R = N-1, ans = -1, mid;
    while(L <= R){
        mid = (L+R)/2;
        if(A[mid] == fnd){
            ans = mid;
            R = mid-1;
        }
        else if(A[mid] > fnd){
            R = mid-1;
        }
        else if(A[mid] < fnd){
            L = mid+1;
        }
    }
    return ans;
}

int main(){
    int pos;
    printf("Array: ");
    for(int i = 0; i < N; ++i)
        printf("%d ", A[i]);
    printf("\n\n");
    pos = BS_FirstOneThatMoreThanOrEqualTo(3);
    if(pos == -1)
        printf("NOT FOUND First one that MORE than or EQUAL to 3!!\n");
    else
        printf("First one that MORE than or EQUAL to 3 is at position %d.\n", pos);
    pos = BS_FirstOneThatMoreThanOrEqualTo(101);
    if(pos == -1)
        printf("NOT FOUND First one that MORE than or EQUAL to 101!!\n\n");
    else
        printf("First one that MORE than or EQUAL to 101 is at position %d.\n\n", pos);

    pos = BS_FirstOneThatEqualTo(100);
    if(pos == -1)
        printf("NOT FOUND First that EQUAL to 100!!\n");
    else
        printf("First one that EQUAL to 100 is at position %d.\n", pos);
    pos = BS_FirstOneThatEqualTo(7);
    if(pos == -1)
        printf("NOT FOUND First that EQUAL to 7!!\n");
    else
        printf("First one that EQUAL to 7 is at position %d.\n", pos);
    return 0;
}
