#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
int n,w,h,sum,a[N],b[N],mxa,mxb;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> h >> w;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum+=a[i];
        if(i>=h){
            sum-=a[i-h];
            mxa = max(mxa, sum);
        }
    }
    sum = 0;
    for(int i=1; i<=n; i++){
        cin >> b[i];
        sum+=b[i];
        if(i>=w){
            sum-=b[i-w];
            mxb = max(mxb, sum);
        }
    }
    //cout << mxa << " " << mxb << "\n";
    cout << mxa*w+mxb*h;
}
