//Task : https://www.codechef.com/problems/CARDSHUF/
//Implicit Treap with lazy propagation

#include <bits/stdc++.h>
using namespace std;

struct node{
    int val, sz, prior;
    node *l, *r;
    bool rev;
    node(int v) : val(v), sz(1), prior(rand()){
        l = r = nullptr;
        rev = 0;
    }
};

inline int gs(node *t){
    return (!t) ? 0 : t->sz;
}

inline void up(node *t){
    if(!t) return;

    t->sz = 1 + gs(t->l) + gs(t->r);
}

inline void push(node *t){
    if(!t) return;

    if(t->rev){
        swap(t->l, t->r);
        if(t->l) (t->l)->rev ^= 1;
        if(t->r) (t->r)->rev ^= 1;
        t->rev = 0;
    }
}

inline void reverse(node *t){
    t->rev ^= 1;
}

void merge(node *&t, node *l, node *r){
    push(l), push(r);

    if(!l or !r) t = (!l) ? r : l;
    else if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;

    up(t);
}

void split(node *t, node *&l, node *&r, int key){
    if(!t) return void(l = r = nullptr);

    push(t);

    int ck = 1+gs(t->l);
    if(key >= ck) split(t->r, t->r, r, key-ck), l = t;
    else split(t->l, l, t->l, key), r = t;

    up(t);
}

void pri(node *t){
    if(!t) return;
    push(t);

    pri(t->l);
    cout << t->val << " ";
    pri(t->r);
}

void pri(const string &s, node *t){
    cout << s;
    pri(t);
    cout << "\n";
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, Q; cin >> n >> Q;
    
    node *root = nullptr;
    for(int i = 1; i <= n; i++) merge(root, root, new node(i));

    while(Q--){
        int a, b, c; cin >> a >> b >> c;

        node *left, *mid, *right;

        split(root, left, mid, a); //1 
        split(mid, mid, right, b); //2

        // pri("LEFT : ", left);
        // pri("Mid : ", mid);
        // pri("Right : ", right);

        merge(root, left, right); //3 now, tree is stored at root and left, right = null
        
        // pri("Operation 3rd : ", root);
        
        split(root, left, right, c); //4 left now has C cards and right has the rest
        
        // pri("Operation 4th : ", left);
        // pri("Operation 4th : ", right);

        reverse(mid);
        merge(mid, mid, right);

        // pri("Operation 5th : ", mid);

        merge(root, left, mid);

        // pri("Operation 6th : ", root);
        // cout << "\n";

    }

    pri(root);

    return 0;
}