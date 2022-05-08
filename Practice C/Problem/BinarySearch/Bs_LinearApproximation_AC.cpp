#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n,a[N];

///https://atcoder.jp/contests/abc102/tasks/arc100_a

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] -= i;
    }

    sort(a+1, a+n+1);
    /*for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";*/

    int l = a[1], r = a[n];
    long long ans = 1e18;
    while(l <= r){
        int mid = (l+r)>>1;
        long long t1 = 0, t2 = 0;

        for(int i = 1; i <= n; i++){
            t1 += abs(a[i]-mid);
            t2 += abs(a[i]-mid-1);
        }
        //cout << mid << " " << t1 << "\n";

        if(t1 < t2){ ///t1 -> current mid, t2 -> next
            r = mid-1;
            ans = t1;
        }else{
            l = mid+1;
        }
    }

    cout << ans << "\n";
    return 0;
}
