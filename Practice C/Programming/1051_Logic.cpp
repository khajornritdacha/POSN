#include<bits/stdc++.h>
#define int long long
using namespace std;
bool ok;
int n,m;
vector<int> a,vi;
vector<vector<int>> de,co;
void gen(int lv = 0){
    if(lv == 26){
        bool now = true;
        for(int i=1; i<=n; i++){
            bool tmp = false;
            for(int d : de[i]){
                if(d < 0){
                    if(vi[(d*-1)-'a'] == -1)
                        tmp = true;
                }else{
                    if(vi[d-'a'] == 1)
                        tmp = true;
                }
            }
            now = now&tmp;
        }
        if(now){
            bool res = true;
            for(int i=1; i<=m; i++){
                bool tmp = false;
                for(int d : co[i]){
                    if(d < 0){
                        if(vi[(d*-1)-'a'] == -1)
                            tmp = true;
                    }else{
                        if(vi[d-'a'] == 1)
                            tmp = true;
                    }
                }
                res = res&tmp;
            }
            if(!res)
                ok = false;
        }
        return;
    }
    if(a[lv]){
        vi[lv] = 1;
        gen(lv+1);
        vi[lv] = -1;
        gen(lv+1);
    }else{
        gen(lv+1);
    }
}
main(){
     ios_base::sync_with_stdio(0); cin.tie(0);
     int t;
     string str;
     cin >> t;
     while(t--){
        de.clear(); co.clear(); a.clear(); vi.clear();
        ok = true;
        cin >> n >> m;
        a.resize(30, 0); de.resize(n+1); co.resize(m+1); vi.resize(30, 0);
        for(int i=1; i<=n; i++){
            int x;
            cin >> x;
            for(int j=1; j<=x; j++){
                cin >> str;
                int tmp = str[1];
                a[tmp-'a'] = 1;
                if(str[0] == '-')
                    tmp*=-1;
                de[i].emplace_back(tmp);
            }
        }
        for(int i=1; i<=m; i++){
            int x;
            cin >> x;
            for(int j=1; j<=x; j++){
                cin >> str;
                int tmp = str[1];
                a[tmp-'a'] = 1;
                if(str[0] == '-')
                    tmp*=-1;
                co[i].emplace_back(tmp);
            }
        }
        gen();
        if(ok)
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
     }
}
