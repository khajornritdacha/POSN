#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,L,nr=1,nc=0,ans;
vector<int> vec;
main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> L;
    vec.emplace_back(1);
    vec.emplace_back(L);
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        vec.emplace_back(x);
    }
    sort(vec.begin(), vec.end());
    for(int i=1; i<=m+1; i++){
        int row,col;
        //cout << "\nNR : " << nr << " " << nc << "\n";
        if(i <= m){
            cin >> row >> col;
        }else{
            row =1, col = 0;
        }
        if(nc == 0){
            if(col == nc){
                if(row < nr){
                    int pos = lower_bound(vec.begin(), vec.end(), nr)-vec.begin();
                    pos = vec[pos];
                    ans += abs(pos-nr)+2;
                    nr = pos;
                    nc = !nc;
                    pos = upper_bound(vec.begin(), vec.end(), row)-vec.begin();
                    pos = vec[pos-1];
                    ans += abs(pos-nr)+2;
                    nr = pos;
                    nc = !nc;
                }
                ans += abs(row-nr);
                nr = row;
            }else{
                ///0 to 1
                //cout << "THIS ONE\n";
                int pos = lower_bound(vec.begin(), vec.end(), max(nr,row))-vec.begin();
                pos = vec[pos];
                ans += abs(pos-nr)+2;
                nr = pos;
                nc = !nc;
                ans += abs(row-nr);
                nr = row;
            }
        }else{
            if(col == nc){
                ///1 to 1
                if(row > nr){
                    //cout << "ROW > NR" << "\n";
                    int pos = upper_bound(vec.begin(), vec.end(), nr)-vec.begin();
                    pos = vec[pos-1];
                    //cout << "Pos : " << pos << "\n";
                    ans += abs(pos-nr)+2;
                    nr = pos;
                    nc = !nc;
                    pos = lower_bound(vec.begin(), vec.end(), row)-vec.begin();
                    pos = vec[pos];
                    ans += abs(pos-nr)+2;
                    nr = pos;
                    nc = !nc;
                }
                ans += abs(row-nr);
                nr = row;
            }else{
                ///1 to 0
                int pos = upper_bound(vec.begin(), vec.end(), min(row,nr))-vec.begin();
                pos = vec[pos-1];
                ans += abs(pos-nr)+2;
                nr = pos;
                nc = !nc;
                ans += abs(row-nr);
                nr = row;
            }
        }
        //cout << ans << "\n";
    }
    cout << ans*50;
}

