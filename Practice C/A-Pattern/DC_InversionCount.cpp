#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 2e5+10;
int n,a[N];
///https://www.spoj.com/problems/INVCNT/

int solve(int l, int r){
    if(l == r)
        return 0;
    int mid = (l+r)/2;
    int res = solve(l, mid)+solve(mid+1, r);
    int i=l, j=mid+1,b[r-l+5],idx=1;

    if(DEBUG){
        printf("L R : %d %d\n", l, r);
        for(int i=l; i<=r; i++){
            printf("%d ", a[i]);
        }
        printf("\nRES : %d\n", res);
    }
    while(i <= mid and j <= r){
        if(a[j] < a[i]){
            res += (mid-i+1);
            b[idx++] = a[j++];
        }else{
            b[idx++] = a[i++];
        }
    }

    while(j <= mid)
        b[idx++] = a[j++];

    while(i <= mid)
        b[idx++] = a[i++];

    for(int i=1; i<idx; i++)
        a[l+i-1] = b[i];

    return res;
}

void test_case(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cout << solve(1, n) << "\n";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
}
