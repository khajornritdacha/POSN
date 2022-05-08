#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

//Treap
//https://beta.programming.in.th/tasks/1147

struct node{
	int val, mx;
	int prior, sz;
	node *l, *r;
	node(int in) : val(in), mx(in), prior(rand()), sz(1), l(nullptr), r(nullptr) {} //initialization
};

inline int gs(node *t){
	return (t) ? t->sz : 0;
}

inline void combine(node *&t, node *l, node *r){
	if(!l or !r){
		t = (!l) ? r : l;
		return;
	}

	t->mx = max(l->mx, r->mx);
}

inline void up(node *t){
	if(!t) return;
	t->sz = 1 + gs(t->l) + gs(t->r);
	t->mx = t->val;
	combine(t, t->l, t);
	combine(t, t, t->r);
}

void split(node *t, node *&l, node*&r, int key){
	if(!t){
		l = r = nullptr;
		return;
	}

	int cur_key = 1 + gs(t->l);
	if(cur_key <= key) split(t->r, t->r, r, key-cur_key), l = t;
	else split(t->l, l, t->l, key), r = t;
	
	up(t);
}

void merge(node *&t, node *l, node *r){
	if(!l or !r) t = (!l) ? r : l;
	else if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	
	up(t);
}

void pri(node *t){
	if(!t) return;
	pri(t->l);
	cout << t->val << " ";
	pri(t->r);
}

void print(node *t, string name){
	cout << name << " : ";
	pri(t);
	cout << "\n";
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, Q; cin >> n >> Q;

	node *root = nullptr;
	for(int i = 1; i <= n; i++) merge(root, root, new node(0));

	while(Q--){
		char ch; cin >> ch;
		node *left, *mid, *right;
		if(ch == 'U'){
			int idx, val; cin >> idx >> val;

			split(root, left, mid, idx-1);
			split(mid, mid, right, 1);
			
			if(DEBUG){
				print(left, "left");
				print(mid, "mid");
				print(right, "right");
			}

			mid->val = val;

			merge(root, left, mid);
			merge(root, root, right);

			if(DEBUG){
				print(root, "root");
			}

		} else {
			int a, b; cin >> a >> b;

			split(root, left, mid, a-1);
			split(mid, mid, right, b-a+1);

			cout << mid->mx << "\n";

			merge(root, left, mid);
			merge(root, root, right);
		}
	}
}