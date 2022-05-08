#include<bits/stdc++.h>
#define int long long
#define a arr[0]
#define b arr[1]
#define c arr[2]
using namespace std;
int arr[5],mn;
main(){
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    cin >> a >> b >> c;
    sort(arr,arr+3);
    int mx = max(b-a,c-b)-1;
    mn = min(b-a,c-b)-1;
    if(mn == 0)
        mn = mx;
    if(mn > 2)
        mn = 2;
    cout << mn << "\n" << mx;
}
