#include <bits/stdc++.h>
using namespace std;

//beta programming -> segment tree

const int N = 3e5+10, INF = 2e9;

int cnt = 1;

struct node{
    int v, lb, ub;
    node *lefc, *rigc;

    node(int ilb = 0, int iub = 0, int iv = 0){
        v = iv, lb = ilb, ub = iub;
        lefc = rigc = nullptr;
    }

    inline void extend(){
        if(!lefc and lb < ub){
            int mid = (lb+ub)>>1;
            lefc = new node(lb, mid);
            rigc = new node(mid+1, ub);
            cnt += 2;
        }
    }

    void up(int idx, int val){
        extend();

        if(lb == ub){
            v = val;
            return;
        }

        if(idx <= lefc->ub){
            lefc->up(idx, val);
        } else {
            rigc->up(idx, val);
        }
        v = max(lefc->v, rigc->v);
        
    }

    int ask(int a, int b){
        if(a > b or ub < a or lb > b) return -INF;
        if(a <= lb and ub <= b) return v;
        extend();
        return max(lefc->ask(a, b), rigc->ask(a, b));
    }


};


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, Q; cin >> n >> Q;
    node *root = new node(1, n);
    
    while(Q--){
        char cd; cin >> cd;
        if(cd == 'U'){
            int idx, val; cin >> idx >> val;
            root->up(idx, val);
        } else if(cd == 'P'){
            int a, b; cin >> a >> b;
            cout << root->ask(a, b) << "\n";
        } else {
            assert(0);
        }
    }

    return 0;
}
