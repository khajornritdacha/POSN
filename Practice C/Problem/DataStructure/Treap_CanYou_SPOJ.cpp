#include <bits/stdc++.h>
using namespace std;

//Implicit Treap
//https://www.spoj.com/problems/GSS6/

struct node{
	int val, ans, mxpre, mxsuf, sum;
	int prior, sz;
	node *l, *r;
	node(int in){
		val = ans = mxpre = mxsuf = sum = in;
		prior = rand();
		sz = 1;
		l = r = nullptr;
	}
};

inline int gs(node *t){
	return (!t) ? 0 : t->sz;
}

inline void combine(node *&t, node *l, node *r){
	if(!l or !r) return void(t = (!l) ? r : l);

	t->ans = max({l->ans, r->ans, l->mxsuf + r->mxpre});
	t->mxpre = max(l->mxpre, l->sum + r->mxpre);
	t->mxsuf = max(r->mxsuf, r->sum + l->mxsuf);
	t->sum = l->sum + r->sum;
}

inline void up(node *t){
	if(!t) return;

	t->sz = 1 + gs(t->l) + gs(t->r);
	t->ans = t->sum = t->mxpre = t->mxsuf = t->val;

	combine(t, t->l, t);
	combine(t, t, t->r);
}

void split(node *t, node *&l, node *&r, int key){
	if(!t) return void(l = r = nullptr);
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

void print(node *t){
	if(!t) return;
	print(t->l);
	cout << t->val << " " << t->ans << " " << t->mxpre << " " << t->mxsuf << " " << t->sum << "\n";
	print(t->r);
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	node *root = nullptr;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		merge(root, root, new node(x));
	}
	
	int Q; cin >> Q;
	while(Q--){
		char ch; cin >> ch;
		node *left, *mid, *right;
		if(ch == 'I'){
			int a, b; cin >> a >> b;
			
			split(root, left, mid, a-1);
			merge(root, left, new node(b));
			merge(root, root, mid);

		} else if(ch == 'D'){
			int a; cin >> a;
			split(root, left, mid, a-1);
			split(mid, mid, right, 1);

			delete mid;

			merge(root, left, right);

		} else if(ch == 'R'){
			int a, b; cin >> a >> b;
			split(root, left, mid, a-1);
			split(mid, mid, right, 1);

			mid->val = b;

			merge(root, left, mid);
			merge(root, root, right);
		} else if(ch == 'Q'){
			int a, b; cin >> a >> b;
			split(root, left, mid, a-1);
			split(mid, mid, right, b-a+1);

			cout << mid->ans << "\n";
			
			// cout << "MID\n";
			// print(mid);
			// cout << "\n";

			merge(root, left, mid);
			merge(root, root, right);
		}

		// cout << "ROOT : ";
		// print(root);
		// cout << "\n";
	}

	return 0;
}