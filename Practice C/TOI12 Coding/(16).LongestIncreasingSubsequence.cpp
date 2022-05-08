#include <cstdio>
#include <vector>
using namespace std;

int P[100005], A[100005], DP[100005];
vector<int> LIS, IDX;

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%d", &A[i]);
        int pos = lower_bound(LIS.begin(), LIS.end(), A[i])-LIS.begin();
        if(pos == IDX.size()){
            LIS.push_back(A[i]);
            IDX.push_back(i);
        }
        else{
            LIS[pos] = A[i];
            IDX[pos] = i;
        }
        if(pos-1 >= 0)
            P[i] = IDX[pos-1];
        DP[i] = pos+1;
    }
    int trav = IDX.back();
    vector<int> Order;
    while(trav != 0){
        Order.push_back(A[trav]);
        trav = P[trav];
    }
    printf("Longest Increasing Subsequence: %d\n", LIS.size());
    printf("Order: ");
    for(int i = Order.size()-1; i >= 0; --i)
        printf("%d ", Order[i]);
    return 0;
}
/*
8
-7 10 9 2 3 8 8 1
*/
