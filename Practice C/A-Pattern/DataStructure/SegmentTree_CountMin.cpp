#include<bits/stdc++.h>
using namespace std;
int n,m;
///tr.first = min tr.second = numbers of min
class segment{
public:
    vector<pair<int,int>> tr;
    void init(){
        tr.resize(2*n,{0,0});
    }
    void con(){
        for(int i=n-1; i; i--){
            if(tr[i*2].first<tr[i*2+1].first)
                tr[i]=tr[i*2];
            else if(tr[i*2].first>tr[i*2+1].first)
                tr[i]=tr[i*2+1];
            else if(tr[i*2].first==tr[i*2+1].first){
                tr[i]=tr[i*2];
                tr[i].second+=tr[i*2+1].second;
            }
        }
    }
    void up(int pos, int val){
        tr[pos+=n-1]={val,1};
        for(int i=pos/2; i; i/=2){
            if(tr[i*2].first<tr[i*2+1].first)
                tr[i]=tr[i*2];
            else if(tr[i*2].first>tr[i*2+1].first)
                tr[i]=tr[i*2+1];
            else if(tr[i*2].first==tr[i*2+1].first){
                tr[i]={tr[i*2].first,tr[i*2].second+tr[i*2+1].second};
            }
        }
    }
    void print(){
        for(auto [x,y] : tr)
            cout << x << " ";
        cout << "\n";
        for(auto [x,y] : tr)
            cout << y << " ";
        cout << "\n";
    }
    void mn(int l, int r){
        int ans=2e9,cnt=0;
        for(l+=n-1,r+=n-1; l<=r; l/=2,r/=2){
            if((l%2)==1){
                if(tr[l].first<ans){
                    ans=tr[l].first;
                    cnt=tr[l].second;
                }else if(ans==tr[l].first){
                    cnt+=tr[l].second;
                }
                //cout << l << " " << tr[l].first << " " << tr[l].second << "\n";
                l++;
            }
            if((r%2)==0){
                if(tr[r].first<ans){
                    ans=tr[r].first;
                    cnt=tr[r].second;
                }else if(ans==tr[r].first){
                    cnt+=tr[r].second;
                }
                r--;
            }
        }
        cout << ans << " " << cnt << "\n";
    }
};
main(){
    cin >> n >> m;
    segment seg;
    seg.init();
    for(int i=1; i<=n; i++){
        cin >> seg.tr[i+n-1].first;
        seg.tr[i+n-1].second=1;
    }
    seg.con();
    //seg.print();
    for(int i=1; i<=m; i++){
        int c,x,y;
        cin >> c >> x >> y;
        if(c==1){
            seg.up(x+1,y);
        }else{
            seg.mn(x+1,y);
        }
        //seg.print();
    }
}
