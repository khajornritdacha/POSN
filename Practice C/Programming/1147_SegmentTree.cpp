#include<bits/stdc++.h>
using namespace std;
vector<int> tree(1000005);
int n,q;
void up(int pos,int val){
    pos+=n-1;
    tree[pos] = val;
    for(int i=pos/2;i>0;i/=2){
        tree[i] = max(tree[i*2],tree[i*2+1]);
    }
}
int qq(int l,int r){
    int ans = -1e9;
    for(l+=n-1,r+=n-1;l<=r;l/=2,r/=2){
        if(l%2==1){
            ans = max(ans,tree[l++]);
        }
        if(r%2==0){
            ans = max(ans,tree[r--]);
        }
    }
    return ans;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   cin >> n >> q;
    while(q--){
        char code;
        cin >> code;
        if(code=='U'){
            int pos,val;
            cin >> pos >> val;
            up(pos,val);
        }else if(code=='P'){
            int x,y;
            cin >> x >> y;
            cout << qq(x,y) << "\n";
        }
    }
}
