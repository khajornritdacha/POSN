#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int mx,n,k;
vector<int> vec;
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x=vec[i];
        int y=upper_bound(vec.begin(),vec.end(),x+k)-vec.begin();
        if(y!=0){
            y--;
        }
        mx=max(mx,y-i);
    }
    cout << mx;
}
