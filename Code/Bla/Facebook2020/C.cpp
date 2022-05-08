#include<bits/stdc++.h>
using namespace std;
using pi=pair<long long,long long>;
int t,cnt;
vector<pi> vec;
unordered_map<long long,long long> mp;
main()
{
    FILE *fi,*fo;
    fi=fopen("timber_input.txt","r");
    fo=fopen("output.txt","w");
    fscanf(fi,"%d",&t);
    while(cnt<t)
    {
        int n;
        long long mx=0;
        fscanf(fi,"%d",&n);
        for(int i=0; i<n; i++)
        {
            int x,y;
            fscanf(fi,"%d%d",&x,&y);
            vec.emplace_back(x,y);
        }
        sort(vec.begin(),vec.end());
        for(int i=0; i<n; i++)
        {
            int p=vec[i].first;
            int s=vec[i].second;
            mp[s+p]=max(mp[s+p],mp[p]+s);
            mp[p]=max(mp[p],mp[p-s]+s);
            mx=max({mx,mp[s+p],mp[p]});
        }
        fprintf(fo,"Case #%d: %d\n",++cnt,mx);
        vec.clear();
        mp.clear();
    }
}
