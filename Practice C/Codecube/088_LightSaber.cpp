#include<bits/stdc++.h>
using namespace std;
int n,a,b,ans[110];
bool sp;
///Approach as blocks
///LDS will count only within the same block (numbers of members of the first block equal to LDS)
///LIS will count only different block (numbers of block equal to LIS)
///Example : 10 3 5
///Ans : 5 4 3 2 1 7 6 10 9 8
///Note : (5 4 3 2 1) -> first block will have size equal to LDS; (7 6) -> 2nd block; (10 9 8) -> 3rd block(leftover block)
main(){
    cin >> n >> a >> b;
    if(a+b-1 > n or a*b < n){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    if(a+b-1 == n){
        for(int i=a, val=n; i; i--)
            ans[i] = val--;
        for(int i=n, val=1; i>a; i--)
            ans[i] = val++;
    }else{
        if(a > b){
            sp = true;
            swap(a,b);
        }
        int val = 1;
        for(int i=b; i>=1; i--)
            ans[i] = val++;
        if(a-1 != 0){
            int sz = (n-b)/(a-1);
            for(int t=1; t<a-1; t++){
                for(int i=b+t*sz; i>b+(t-1)*sz; i--){
                    ans[i] = val++;
                }
            }
            int leftover = b+(a-2)*sz;
            for(int i=n; i>leftover; i--)
                ans[i] = val++;
        }
    }
    if(sp){
        for(int i=n; i>=1; i--)
            cout << ans[i] << " ";
    }else{
        for(int i=1; i<=n; i++)
            cout << ans[i] << " \n"[i==n];
    }
}
