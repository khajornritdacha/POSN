#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class RMQ {
private:
	int sz;
	std::vector<int> val;
public:
	RMQ() : sz(0), val() {};
	RMQ(int N) {
		sz = 1;
		while(sz < N) {
			sz *= 2;
		}
		val = vector<int>(sz * 2, 0);
	}
	void update(int pos, int x) {
		pos += sz;
		val[pos] = x;
		while(pos > 1) {
			pos >>= 1;
			val[pos] = max(val[pos * 2], val[pos * 2 + 1]);
		}
	}
	int rangemax(int l, int r) {
		l += sz; r += sz;
		int ans = 0;
		while(l != r) {
			if(l & 1) ans = max(ans, val[l++]);
			if(r & 1) ans = max(ans, val[--r]);
			l >>= 1; r >>= 1;
		}
		return ans;
	}
};
int solve(int N, int D, vector<int> A) {
	vector<int> perm(N);
	for(int i = 0; i < N; ++i) {
		perm[i] = i;
	}
	sort(perm.begin(), perm.end(), [&](int i, int j) {
		return A[i] != A[j] ? A[i] < A[j] : i > j;
	});
	RMQ seg(N);
	set<int> st;
	st.insert(-1);
	st.insert(N);
	set<int> barrier;
	for(int i = 0; i < N - D; ++i) {
		barrier.insert(i);
	}
	for(int i : perm) {
		set<int>::iterator it = st.lower_bound(i);
		int pr = *it, pl = *(--it);
		if(pr - pl > D) {
			if(pr - i <= D) {
				for(int j = i; j <= pr; ++j) {
					barrier.erase(j);
				}
			}
			if(i - pl <= D) {
				for(int j = pl; j <= i; ++j) {
					barrier.erase(j);
				}
			}
		}
		st.insert(i);
		it = barrier.lower_bound(i);
		int leftmost = (it == barrier.begin() ? 0 : *(--it));
		int res = seg.rangemax(leftmost, i);
		seg.update(i, res + 1);
	}
	int answer = seg.rangemax(0, N);
	return answer;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, D;
	cin >> N >> D;
	vector<int> A(N);
	for(int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	cout << solve(N, D, A) << endl;
	return 0;
}
