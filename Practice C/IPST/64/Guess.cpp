//if K = 1 then each time the number of suspect place must decrease into a third. We have 3 colors : red, yellow, black
//if K = 2 then it must decrese into a fourth. We have 4 colors : red, blue, yellow, black

#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

//I don't have grader file, so I created my own instead.
#ifdef LOCAL
	char ask(vector<pair<int, char>> query);
#else
	#include "guess.h"
#endif

int find_answer(int N, int K){
	vector<int> left;
	vector<bool> chk(N, 1);
	for(int i = 0; i < N; i++){
		left.emplace_back(i);
	}

	int pre = N, cd = 0;
	if(N == 729 or K == 1) cd = 1;

	while(left.size() > 1){

		if(DEBUG){
			cout << "LEFT = " << left.size() << "\n";
			for(int lf : left) cout << lf << " ";
			cout << "\n";
		}

		int cr = 0, cy = 0, cb = 0, sz = left.size(), want = (sz+3)/4;

		if(cd) want = (sz+2)/3;

		vector<pair<int, char>> qq;
		vector<char> co(N);
		for(int i = 0; i < (int)left.size(); i++){
			if(co[left[i]]) continue;

			if(cd){
				if(cr < want){
					qq.emplace_back(left[i], 'R');
					cr++;
					co[left[i]] = 'R';

					if(left[i]+1 < N and chk[left[i]+1]){
						cy++;
						co[left[i]+1] = 'C';
					}
				} else if(cy < want){
					assert(left[i]-1 >= 0 and co[left[i]-1] == 0);

					qq.emplace_back(left[i]-1, 'R');
					co[left[i]] = 'C';
					cy++;
				}
			} else {
				if(cr < want){
					co[left[i]] = 'R';
					cr++;
					qq.emplace_back(left[i], 'R');

					if(i+1 < N and left[i]+1 == left[i+1] and cy+1 <= want-1){
						co[left[i]+1] = 'C';
						cy++;
						i++;
					}
				} else if(cb < want){
					co[left[i]] = 'B';
					cb++;
					qq.emplace_back(left[i], 'B');

					if(cb == want and i+1 < N and left[i]+1 == left[i+1]){
						assert(cy+1 <= want);

						co[left[i]+1] = 'C';
						cy++;
						i++;
					}
				} else if(cy < want){
					assert(left[i]-1 >= 0 and chk[left[i]-1] == false);

					co[left[i]] = 'C';
					cy++;
					qq.emplace_back(left[i]-1, 'R');
				}

			}
		}

		char res = ask(qq);

		if(DEBUG){
			cout << "RES : " << res << "\n\n";
		}

		vector<int> con;
		if(res != 'X'){
			for(int i = 0; i < (int)left.size(); i++){
				if(co[left[i]] == res) con.emplace_back(left[i]);
				else chk[left[i]] = false;
			}
		} else {
			for(int i = 0; i < (int)left.size(); i++){
				if(co[left[i]] == 0) con.emplace_back(left[i]);
				else chk[left[i]] = false;
			}
		}

		left = con;
		
		if(DEBUG){
			assert((int)left.size() != pre);
			pre = left.size();
		}
	}

	return left[0];
}

#ifdef LOCAL

int ans;

char ask(vector<pair<int, char>> query){
	char res = 'X';
	for(auto [x, y] : query){
		if(x == ans){
			res = y;
		} else if(x+1 == ans or x-1 == ans){
			if(res != 'R' and res != 'B'){
				res = 'C';
			}
		}
	}
	return res;
}


int main(void){
	int N, K; cin >> N >> K >> ans;
	int res = find_answer(N, K);

	cout << "RESULT : " << res << "\n";
	if(res == ans){
		cout << "Correct\n";
	} else {
		cout << "Incorrect\n";
	}
	return 0;
}

#endif