#include <cstdio>
#include <vector>
using namespace std;

class OBJECT{
public:
    int w, v;
    OBJECT(int w, int v){
        this->w = w;
        this->v = v;
    }
};

int dp[100005];
vector<OBJECT> obj;

int main(){
    int W, N;
    printf("Enter W N: ");
    scanf("%d%d", &W, &N);
    for(int i = 1; i <= N; ++i){
        int wi, vi;
        printf("Enter (w%d,v%d): ", i, i);
        scanf("%d%d", &wi, &vi);
        obj.push_back(OBJECT(wi, vi));
    }
    printf("===================================================\n");
    for(int i = 0; i < N; ++i){
        printf("(%d): ", i);
        for(int j = W; j >= obj[i].w; --j){
            dp[j] = max(dp[j], dp[j-obj[i].w]+obj[i].v);
        }
        for(int i = 1; i <= W; ++i)
            printf("%2d ", dp[i]);
        printf("\n");
    }
    printf("We can make maximum VALUE '%d' by our %d Weight Bag.", dp[W], W);
    return 0;
}
/*
16 4
10 10
5 20
4 9
5 15
*/
