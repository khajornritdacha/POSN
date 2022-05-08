#include<bits/stdc++.h>
using namespace std;
struct loc{
    int x,y,z;
};
struct ele{
    int mo,ke,cp;
};
int n,m;
loc pos[15],st;
ele ipt[15];
bool visit[15];
int ans=1e9;
void func(int lv){
    if(lv==m+1){
        int temp=0,mon=0,key=0,cpu=0;
        int xx = st.x,yy = st.y,zz = st.z;
        for(int i=1;i<=m;i++){
            if(visit[i]){
                temp+=((pos[i].x-xx)*(pos[i].x-xx))+((pos[i].y-yy)*(pos[i].y-yy))+((pos[i].z-zz)*(pos[i].z-zz));
                xx = pos[i].x;
                yy = pos[i].y;
                zz = pos[i].z;
                mon+=ipt[i].mo;
                key+=ipt[i].ke;
                cpu+=ipt[i].cp;
            }
        }
        if(mon>=n&&key>=n&&cpu>=n){
            ans = min(ans,temp);
        }
        return;
    }
    for(int i=0;i<=1;i++){
        visit[lv] = i;
        func(lv+1);
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> st.x >> st.y >> st.z;
    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> pos[i].x >> pos[i].y >> pos[i].z;
        cin >> ipt[i].mo >> ipt[i].ke >> ipt[i].cp;
    }
    func(1);
    cout << ans;
}

