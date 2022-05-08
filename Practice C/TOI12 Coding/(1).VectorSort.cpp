#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class CLASS{
public:
    int a, b, c;
    CLASS(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    bool operator < (const CLASS &A){
        if(this->a == A.a){
            if(this->b == A.b)
                return this->c > A.c;
            else
                return this->b < A.b;
        }
        else
            return this->a > A.a;
    }
};

vector<CLASS> vec;
bool cmp(const CLASS &A, const CLASS &B){
    if(A.a == B.a){
        if(A.b == B.b)
            return A.c > B.c;
        else
            return A.b < B.b;
    }
    else
        return A.a > B.a;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        vec.push_back(CLASS(a, b, c));
    }
    //sort(vec.begin(), vec.end());
    printf("---SORT---\n");
    for(int i = 0; i < vec.size(); ++i){
        printf("%d %d %d\n", vec[i].a, vec[i].b, vec[i].c);
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
