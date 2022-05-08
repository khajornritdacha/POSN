#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
int n;
bool ans[N],chk[N];
vector<int> vec[N];

int dfs(int u, int p, int K){
    map<int,int> cnt;
    vector<int> chua;
    bool ok = true;
    for(int v : vec[u]){
        if(v == p) continue;
        int tmp = dfs(v, u, K)+1;
        if(ans[K] == false) ///without this line of code we will get TE
            return 0;
        if(tmp != K){
            cnt[tmp]++;
            chua.emplace_back(tmp);
        }
    }

    for(int ch : chua){
        int re = abs(K-ch);
        if(cnt[ch] == 0 or cnt[re] == 0)
            continue;
        if(re == ch){
            if(cnt[re] >= 2)
                cnt[re] -= 2;
        }else{
            if(cnt[ch] > 0 and cnt[re] > 0){
                cnt[re]--, cnt[ch]--;
            }
        }
    }

    int se = 0;
    for(auto it=cnt.begin(); it!=cnt.end(); it++){
        if(it->second != 0){
            if(se != 0 or it->second > 1)
                ok = false;
            se = it->first;
        }
    }

    ans[K] &= ok;
    return se;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    cin >> n;
    for(int i=1; i<n; i++){
        int u,v;
        cin >> u >> v;
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
    for(int i=1; i<n; i++){
        if((n-1)%i == 0 and !chk[i]){
            if(DEBUG){
                cout << "ST : " << i << "\n\n";
            }
            ans[i] = true;
            dfs(1, -1, i);
            if(!ans[i]){ ///if 2 can be accomplish then mutiplier of 2 cannot be accomplish as well
                for(int j=i; j<=n; j+=i)
                    chk[j] = true;
            }
        }
    }
    for(int i=1; i<n; i++)
        cout << ans[i];
}

