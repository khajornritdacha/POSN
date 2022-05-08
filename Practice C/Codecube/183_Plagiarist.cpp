#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,id[N],fen[N];
int qs(int i){
    int sum = 0;
    while(i){
        sum += fen[i];
        i-=i&-i;
    }
    return sum;
}
void up(int i, int val){
    while(i<=n){
        fen[i] += val;
        i+=i&-i;
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> id[i];
        up(i, 1);
    }
    for(int i=1; i<=n; i++){
        int b;
        cin >> b;
        int l=1,r=n,mid,ans=n;
        while(l<=r){
            mid = (l+r)/2;
            if(qs(mid)>=b){
                ans = min(ans, mid);
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        cout << id[ans] << "\n";
        up(ans, -1);
    }
}
///https://beta.programming.in.th/tasks/codecube_183
