#include <cstdio>
#include <queue>
using namespace std;

class CLASS{
public:
    int a, b, c;
    CLASS(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

struct cmp{
    bool operator() (const CLASS &A, const CLASS &B){
        if(A.a == B.a){
            if(A.b == B.b)
                return !(A.c > B.c);
            else
                return !(A.b < B.b);
        }
        else
            return !(A.a > B.a);
    }
};

priority_queue<CLASS, vector<CLASS>, cmp> pq;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        pq.push(CLASS(a, b, c));
    }
    printf("---SORT---\n");
    while(!pq.empty()){
        int a = pq.top().a, b = pq.top().b, c = pq.top().c;
        pq.pop();
        printf("%d %d %d\n", a, b, c);
    }
    return 0;
}
/*
a max -> min
b min -> max
c max -> min

6
1 2 3
1 3 2
1 2 4
3 2 4
5 1 2
5 1 1
*/
