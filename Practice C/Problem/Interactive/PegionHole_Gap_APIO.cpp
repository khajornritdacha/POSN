#include "gap.h"
#include <bits/stdc++.h>
using namespace std;

//https://oj.uz/problem/view/APIO16_gap

long long findGap(int T, int N)
{
    if(T == 1){
        long long arr[N] = {}, l = 0, r = N-1;
        for(; l <= r; l++, r--){
            if(l == 0) MinMax(0, 1e18, &arr[l], &arr[r]);
            else MinMax(arr[l-1]+1, arr[r+1]-1, &arr[l], &arr[r]);
        }

        long long ans = 0;
        for(int i = 0; i < N-1; i++){
            ans = max(ans, arr[i+1]-arr[i]);
        }

        // for(int i = 0; i < N; i++) cout << arr[i] << " \n"[i==N-1];

        return ans;
    }
    
    if(T == 2){
        long long L, R;
        MinMax(0, 1e18, &L, &R);

        long long sz = (R-L-1)/(N-1), l = L+1, pre = L, ans = 0, cnt = 0;
        while(l < R){
            long long r = min(R-1, l+sz-1), mn, mx;
            if(++cnt == N){
                r = R-1;
            }
            if(l > r) break;
            MinMax(l, r, &mn, &mx);

            if(mn != -1){
                ans = max(ans, mn-pre);
                pre = mx;
            }
            l = r+1;
        }

        assert(cnt <= N);

        ans = max(ans, R-pre);

        return ans;
    }

	//return 0;
}
