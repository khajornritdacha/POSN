#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

//Answer Yes iff(if and only if) min([a, b]) = a and max([a, b]) = b
//Use treap to check (cuz I'm learing treap)
//Check only sum is not enough. For instance, [2, 1, 3, 5, 4] sum of range [2, 4] = 9 but in range [2, 4] doesn't contain 2 and 4, so it is not correct 

struct node{
	int val, mn, mx;
	int prior, sz;
	node *l, *r;
	node(int in){
		val = mn = mx = in;
		prior = rand();
		sz = 1;
		l = r = nullptr;
	}
};

inline int gs(node *t){
	return (t) ? t->sz : 0;
}

inline int gmn(node *t){
	return (t) ? t->mn : INF;
}

inline int gmx(node *t){
	return (t) ? t->mx : -INF;
}

inline void up(node *t){
	if(!t) return;
	t->sz = 1 + gs(t->l) + gs(t->r);

	t->mn = min({t->val, gmn(t->l), gmn(t->r)});
	t->mx = max({t->val, gmx(t->l), gmx(t->r)});	
}

void split(node *t, node *&l, node *&r, int key){
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

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, Q; cin >> n >> Q;

	node *root = nullptr;
	for(int i = 1; i <= n; i++) merge(root, root, new node(i));

	while(Q--){
		int cd, a, b; cin >> cd >> a >> b;
		a++, b++;
		node *left, *mid, *right, *A, *B;

		if(cd == 0){
			split(root, left, A, a-1);
			split(A, A, mid, 1);
			split(mid, mid, B, b-a-1);
			split(B, B, right, 1);

			swap(A->val, B->val);

			merge(root, left, A);
			merge(root, root, mid);
			merge(root, root, B);
			merge(root, root, right);
		} else if(cd == 1){
			split(root, left, mid, a-1);
			split(mid, mid, right, b-a+1);

			if(mid->mn == a and mid->mx == b) cout << "YES\n";
			else cout << "NO\n";

			merge(root, left, mid);
			merge(root, root, right);
		}
	}

	return 0;
}