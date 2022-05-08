#include <stdio.h>
#include <math.h>


int main(void){
	const int INF = 21;
	
	int n; scanf("%d", &n);

	int goal = 0, min = INF;
	for(int i = 0; i < n; i++){
		int x; scanf("%d", &x);
		goal |= x<<i;
	}

	//try every combination of flipping each bit (1 for flip and 0 for not)
	for(int bit = 0, lim = 1<<n; bit < lim; bit++){
		int result = 0, used = 0;
		for(int i = 0; i < n; i++){
			int cur = ((bit&(1<<i)) != 0); //get the state of i-th bit whether it has to be filpped or not.
			used += cur;

			if(i > 0){
				result ^= (cur<<(i-1));
			}
			result ^= (cur<<i);
			if(i+1 < n){
				result ^= (cur<<(i+1));
			}
		}

		if(result == goal && used < min){
			min = used;
		}
	}

	if(min == INF){
		min = -1;
	}
	printf("%d\n", min);

	return 0;
}