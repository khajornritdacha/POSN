#include<bits/stdc++.h>
using namespace std;
int n,u,v,temp,te,a[300010],ans;
vector <int> vec[300010],visit[300010];
//vector < pair<int,int> > visit[300010];
queue < pair<int,int> > qq;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        temp = max(u,v);
        te = min(u,v);
        vec[te].push_back(temp);
        visit[te].push_back(0);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<vec[i].size();j++){
            temp = vec[i][j];
            int now = a[i]+1;
            if(now>a[temp]){
                a[temp] = now;
            }
        }
    }
    for(int i=1;i<=n;i++){
       ans = max(ans,a[i]);
    }

    cout << ans+1;
    /*for(int i=1;i<=n;i++){
        for(int j=0;j<vec[i].size();j++){
       cout << i << " " << vec[i][j] << " ";
    }
    cout << endl;
    }*/
}
