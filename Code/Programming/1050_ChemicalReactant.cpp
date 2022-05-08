#include<bits/stdc++.h>
using namespace std;
vector<int> vec[100005],fd;
map<vector<int>,int> mp;
int n,p;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> p;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++){
            int x;
            cin >> x;
            vec[i].emplace_back(x);
        }
    }
    for(int i=1;i<=p;i++){
        int x;
        cin >> x;
        fd.emplace_back(x);
    }
    for(int i=1;i<=n;i++){
        if(vec[i]==fd){
            cout << i << "\n";
            return 0;
        }
        vector<int> temp;
        int code=0;
        for(int j=0;j<p;j++){
            int sum = fd[j]-vec[i][j];
            if(sum<=0){
                code = 1;
                break;
            }
            temp.emplace_back(sum);
        }
        if(!code) mp[temp] = i;
    }
    for(int i=1;i<=n;i++){
        if(mp.count(vec[i])!=0&&mp[vec[i]]!=i){
            cout << min(mp[vec[i]],i) << " " << max(mp[vec[i]],i);
            return 0;
        }
    }
    cout << "NO";
}
