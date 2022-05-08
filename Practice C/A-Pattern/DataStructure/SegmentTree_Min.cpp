#include<bits/stdc++.h>
using namespace std;
int n,m;
class segment{
public:
    vector<long long> tr;
    void init(){
        tr.resize(2*n,0);
    }
    void con(){
        for(int i=n-1; i; i--){
            tr[i]=min(tr[2*i],tr[2*i+1]);
        }
    }
    void up(int pos, int val){
        tr[pos+=n-1]=val;
        for(int i=pos/2; i; i/=2){
            tr[i]=min(tr[2*i],tr[2*i+1]);
        }
    }
    void print(){
        for(long long x : tr)
            cout << x << " ";
        cout << "\n";
    }
    long long mn(int l, int r){
        long long ans=2e18;
        for(l+=n-1,r+=n-1; l<=r; l/=2,r/=2){
            if((l%2)==1)
                ans=min(ans,tr[l++]);
            if((r%2)==0)
                ans=min(ans,tr[r--]);
        }
        return ans;
    }
};
main(){
    cin >> n >> m;
    segment seg;
    seg.init();
    for(int i=1; i<=n; i++){
        cin >> seg.tr[i+n-1];
    }
    seg.con();
    for(int i=1; i<=m; i++){
        int c,x,y;
        cin >> c >> x >> y;
        if(c==1){
            seg.up(x+1,y);
        }else{
            cout << seg.mn(x+1,y) << "\n";
        }
        //seg.print();
    }
}
