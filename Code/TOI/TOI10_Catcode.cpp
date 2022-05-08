#include<bits/stdc++.h>
using namespace std;
int k,m,n,d,cnt=1,l;
bool visit[105][100005],code;
vector<int> vec[105];
unordered_map<long long,int> ump;
string str;
long long con = 1;
void kmp(){
    long long want=0;
    for(int i=0;i<str.size();i++){
        want = want*31+str[i];
    }
    ump[want] = cnt;
}
void solve(){
    long long found=0;
    for(int i=0;i<str.size();i++){
        found = found*31+str[i];
        if(i>=m-1){
            if(i>=m)
                found-=(con*str[i-m]);
        int x = ump.count(found);
        //cout << x << " ";
        if(x!=0){
            int y = ump[found];
            //cout << n << " " << y << "\n";
            if(!visit[n][y]){
                vec[n].emplace_back(y);
                visit[n][y] = true;
                code = true;
            }
        }
        }
    }
}
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> k >> m;
    for(int i=0;i<k;i++){
        cin >> str;
        kmp();
        cnt++;
    }
    for(int i=0;i<m;i++){
        con*=31;
    }
    cin >> n;
    int ss;
    while(n--){
        code = false;
        cin >> ss >> str;
        solve();
        if(!code){
            cout << "OK\n";
        }else{
            sort(vec[n].begin(),vec[n].end());
            for(int i=0;i<vec[n].size();i++){
                cout << vec[n][i] << " ";
            }
            cout << "\n";
        }
    }
}
