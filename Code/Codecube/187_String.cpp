#include <bits/stdc++.h>
using namespace std;

//Implicit Treap with lazy propagation
//https://cp-algorithms.com/data_structures/treap.html#implicit-treaps

struct node{
	int sz, prior;
	char ch;
	bool rev;
	node *l, *r;
	node(char in){
		rev = 0;
		ch = in;
		sz = 1;
		prior = rand();
		l = r = nullptr;
	}
};

inline int gs(node *t){
	return (t) ? t->sz : 0;
}

inline void up(node *t){
	if(t) t->sz = 1 + gs(t->l) + gs(t->r);
}

inline void push(node *t){
	if(t and t->rev){
		swap(t->l, t->r);
		t->rev = 0;
		if(t->l) t->l->rev ^= 1;
		if(t->r) t->r->rev ^= 1; 
	}
}

void split(node *t, node *&l, node *&r, int key){
	push(t);
	if(!t) return void(l = r = nullptr);

	int cur_key = 1 + gs(t->l);
	if(cur_key <= key) split(t->r, t->r, r, key-cur_key), l = t;
	else split(t->l, l, t->l, key), r = t; 
	
	up(t);
}

void merge(node *&t, node *l, node *r){
	push(l), push(r);
	if(!l or !r) return void(t = (!l) ? r : l);

	if(l->prior > r->prior) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;

	up(t);
}

void reverse(node *&t, int a, int b){
	node *left, *mid, *right;
	split(t, left, mid, a-1);
	split(mid, mid, right, b-a+1);

	mid->rev ^= 1;

	merge(t, left, mid);
	merge(t, t, right);
}

void insert(node *&t, int x, string &str){
	node *left, *mid, *right;
	split(t, left, right, x);

	mid = nullptr;
	for(char c : str) merge(mid, mid, new node(c));

	merge(t, left, mid);
	merge(t, t, right); 
}

void print(node *t){
	if(!t) return;
	push(t); //Always push before do anything
	print(t->l);
	cout << t->ch;
	print(t->r);
}

int main(void){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str;
	int Q;

	cin >> str;
	cin >> Q;

	node *root = nullptr;
	for(char c : str) merge(root, root, new node(c));

	while(Q--){
		char cd; cin >> cd;
		if(cd == 'R'){
			int i, j; cin >> i >> j;
			reverse(root, i, j);
		} else if(cd == 'I'){
			int x;
			string K; cin >> x >> K;
			insert(root, x, K);
		}

		// print(root);
		// cout << "\n";
	}

	print(root);

	return 0;
}