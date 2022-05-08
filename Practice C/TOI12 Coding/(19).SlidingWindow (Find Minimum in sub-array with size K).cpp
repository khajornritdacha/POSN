#include <cstdio>
#include <deque>
#include <vector>
using namespace std;

int A[1000005], N, K;

void SlidingWindow(){
    deque<pair<int, int> > window;
    for(int i = 1; i <= N; ++i){
        while(!window.empty() && window.back().first >= A[i])
            window.pop_back();
        window.push_back(make_pair(A[i], i));
        while(window.front().second <= i-K)
            window.pop_front();
        if(i >= K)
            printf("Min from A[%d]...A[%d] is %d\n", i-K+1, i, window.front().first);
    }
}

int main(){
    printf("Enter N K: ");
    scanf("%d%d", &N, &K);
    printf("Enter Arr: ");
    for(int i = 1; i <= N; ++i)
        scanf("%d" ,&A[i]);
    SlidingWindow();
    return 0;
}
/*
7 1
0 5 5 3 10 0 4

7 3
0 5 5 3 10 0 4
*/
