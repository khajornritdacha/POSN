#include <bits/stdc++.h>
using namespace std;

const long long INF = 2e9;

//evaluator -> apr_array

struct node{
    long long sum, lazy, cv;
    unsigned int lb, ub;
    node *lefc, *rigc;

    node(unsigned int ilb, unsigned int iub, long long icv) : lazy(INF){
        lb = ilb, ub = iub, cv = icv;
        sum = 1ll*(ub-lb+1)*cv;
        lefc = rigc = nullptr;
    }

    inline void extend(){
        if(!lefc){
            unsigned int mid = (lb+ub)>>1;
            lefc = new node(lb, mid, cv);
            rigc = new node(mid+1, ub, cv);
        }
    }

    inline void push(){
        if(lazy == INF) return;
        sum = 1ll*lazy*(ub-lb+1);
        cv = lazy;
        if(lefc){
            lefc->lazy = rigc->lazy = lazy;
        }
        lazy = INF;
    }

    void up(unsigned int a, unsigned int b, long long val){
        extend(); //always at this position or else bug will incur
        push();
        if(a > b or b < lb or a > ub) return;

        if(a <= lb and ub <= b){
            lazy = val;
            push();
            return;
        }

        lefc->up(a, b, val), rigc->up(a, b, val);

        sum = lefc->sum + rigc->sum;
    }

    long long ask(unsigned int a, unsigned int b){
        extend(); //always place at the top
        push();
        if(a > b or b < lb or a > ub) return 0;
        if(a <= lb and ub <= b){
            return sum;
        }

        return lefc->ask(a, b) + rigc->ask(a, b);
    }


};

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    unsigned int n, Q; cin >> n >> Q;
    node *root = new node(1, n, 0);

    while(Q--){
        int cd; cin >> cd;
        if(cd == 0){
            unsigned int a, b;
            long long v;
            cin >> a >> b >> v;
            a++;
            root->up(a, b, v);
        } else if(cd == 1){
            unsigned int a, b; cin >> a >> b;
            a++;
            cout << root->ask(a, b) << "\n";
        }
    }

    return 0;
}