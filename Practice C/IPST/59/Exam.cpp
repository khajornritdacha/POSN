//MO algorithm for solving offline range query

#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+10, BS = 200, MXQ = 1e6+10;

struct DATA{
    int l, r, idx;
    DATA(int a, int b, int c){
        l = a, r = b, idx = c;
    }
};

int n, arr[N], Q, ans[MXQ];
vector<DATA> qq;

class MO{
private:   
    int cl, cr, res;
    vector<int> hsh, cnt;
    inline void compress(){
        cnt.resize(N, 0), hsh.resize(N, 0);
        
        vector<int> tmp;
        for(int i = 1; i <= n; i++) tmp.emplace_back(arr[i]);
        sort(tmp.begin(), tmp.end());
        tmp.resize(unique(tmp.begin(), tmp.end())-tmp.begin());
        for(int i = 1; i <= n; i++){
            int k = lower_bound(tmp.begin(), tmp.end(), arr[i])-tmp.begin();
            hsh[i] = k+1;
        }

    }
    inline void ad(int idx){
        if(++cnt[hsh[idx]] > 1) res++;
        // cout << "ADD: " << idx << " " << hsh[idx] << " " << cnt[hsh[idx]] << "\n";
    }
    inline void re(int idx){
        if(--cnt[hsh[idx]] >= 1) res--;
        // cout << "REM: " << idx << " " << hsh[idx] << " " << cnt[hsh[idx]] << "\n";
    }
public:
    MO() : cl(1), cr(0), res(0) { //constructor
        compress();
    }
    ~MO() {} //deconstructor
    
    inline int get(int x){
        return (x == 0 ? cr : cl);
    }
    
    inline void add(int x){
        if(x == 0){
            cr++, ad(cr);
        } else {
            cl--, ad(cl);
        }
    }
    
    inline void rem(int x){
        if(x == 0){
            re(cr), cr--; 
        } else {
            re(cl), cl++;
        }
    }

    inline int getans(){
        return res;
    }

    void chk(){
        cout << "CHK\n";
        for(int i = 0; i < n; i++) cout << cnt[i] << " ";
        cout << "\n";
    }
};

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    cin >> Q;
    for(int i = 1; i <= Q; i++){
        int l, r; cin >> l >> r;
        l++, r++;
        DATA in(l, r, i);
        qq.push_back(in);
    }
    sort(qq.begin(), qq.end(), [&](const DATA &A, const DATA &B){
        if(A.l/BS != B.l/BS) return A.l < B.l;
        return A.r < B.r;
    });

    MO mo;
    for(DATA q : qq){
        while(mo.get(0) < q.r){ //0 for cr and 1 for cl
            mo.add(0);
        }
        while(mo.get(1) > q.l){
            mo.add(1);
        }

        while(mo.get(0) > q.r){
            mo.rem(0);
        }
        while(mo.get(1) < q.l){
            mo.rem(1);
        }

        // cout << q.l << " " << q.r << " " << mo.get(1) << " " << mo.get(0) << "\n";
        // mo.chk();
        ans[q.idx] = mo.getans();
    }

    for(int i = 1; i <= Q; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}