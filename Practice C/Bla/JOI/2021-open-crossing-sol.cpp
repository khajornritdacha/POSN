#include <stdio.h>

typedef long long int ll;

int n, q;

char sa[252525], sb[252525], sc[252525];
char t0[252525];

int l[252525], r[252525];
char c[252525];


bool result[252525];
char str[12][252525];
int slen = 0;

ll base = 1 << 18;
ll seg[1 << 19], lazy[1 << 19];
ll memo[1 << 19];

void eval (ll v) {
	if (lazy[v] == -1) return;

	ll val = ((lazy[v] == memo[v]) ? 1 : 0);
	seg[v] = val;

	if (v < base) {
		lazy[v * 2] = lazy[v];
		lazy[v * 2 + 1] = lazy[v];
	}

	lazy[v] = -1;
}
void resetseg (ll v) {
	if (v < base) seg[v] = (seg[v * 2] & seg[v * 2 + 1]);
}
ll find_ (ll l, ll r, ll beg, ll end, ll i) {
	eval(i);
	if (r <= beg || end <= l) return 0;
	if (l <= beg && end <= r) {
		return seg[i];
	}

	ll med = (beg + end) / 2;
	ll vl = find_(l, r, beg, med, i * 2);
	ll vr = find_(l, r, med, end, i * 2 + 1);

	resetseg(i);

	return (vl & vr);
}
ll find (ll l, ll r) {
	return find_(l, r, 0, base, 1);
}
void update_ (ll l, ll r, ll x, ll beg, ll end, ll i) {
	if (l <= beg && end <= r) {
		lazy[i] = x;
		eval(i);
		return;
	}
	eval(i);
	if (r <= beg || end <= l) return;

	ll med = (beg + end) / 2;
	update_(l, r, x, beg, med, i * 2);
	update_(l, r, x, med, end, i * 2 + 1);

	resetseg(i);

}
void update (ll l, ll r, ll x) {
	update_(l, r, x, 0, base, 1);
}

void func (int index) {
	char toc[3] = {'J', 'O', 'I'};
	int toi[128] = {0};
	toi['J'] = 0;
	toi['O'] = 1;
	toi['I'] = 2;

	for (int i = 0; i < base; i++) {
		if (i < n) {
			memo[base + i] = (1 << toi[str[index][i]]);
			seg[base + i] = ((t0[i] == str[index][i]) ? 1 : 0);
		} else {
			memo[base + i] = 0;
			seg[base + i] = 1;
		}
		lazy[base + i] = -1;
	}
	for (int i = base - 1; i; i--) {
		memo[i] = (memo[i * 2] | memo[i * 2 + 1]);
		seg[i] = (seg[i * 2] & seg[i * 2 + 1]);
		lazy[i] = -1;
	}

	int ti = 0;
	while (true) {
		if (find(0, base)) {
			result[ti] = 1;
		}
		if (ti == q) break;

		update(l[ti], r[ti], (1 << toi[c[ti]]));
		ti++;
	}
}

int main (void) {
	scanf("%d", &n);
	scanf("%s", sa);
	scanf("%s", sb);
	scanf("%s", sc);

	scanf("%d", &q);
	scanf("%s", t0);
	for (int i = 0; i < q; i++) {
		scanf("%d%d %c", &l[i], &r[i], &c[i]);
		l[i]--;
	}


	char toc[3] = {'J', 'O', 'I'};
	int toi[128] = {0};
	toi['J'] = 0;
	toi['O'] = 1;
	toi['I'] = 2;

	slen = 9;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int ki = (6 + 1 - i - j) % 3;

			for (int li = 0; li < n; li++) {
				int sum = 0;
				sum += toi[sa[li]] * i;
				sum += toi[sb[li]] * j;
				sum += toi[sc[li]] * ki;

				str[i * 3 + j][li] = toc[sum %= 3];
			}
		}
	}

	for (int i = 0; i < slen; i++) {
		func(i);
	}
	for (int i = 0; i <= q; i++) {
		puts(result[i] ? "Yes" : "No");
	}

	return 0;
}
