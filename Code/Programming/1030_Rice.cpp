#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<double,int>> vec;
main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        double mon;
        scanf("%d%d",&x,&y);
        mon = (double)x/y;
        vec.emplace_back(mon,y);
    }
    sort(vec.begin(),vec.end());
    /*for(auto x:vec)
        cout << x.first << " " << x.second << "\n";*/
    scanf("%d",&m);
    int pos=0;
    while(m--){
        int ipt;
        scanf("%d",&ipt);
        double temp=0;
        while(1){
            if(vec[pos].second>=ipt){
                vec[pos].second-=ipt;
                temp+=ipt*vec[pos].first;
                printf("%.3f\n",temp);
                if(vec[pos].second==0)
                    pos++;
                break;
            }else{
                temp+=vec[pos].first*vec[pos].second;
                ipt-=vec[pos].second;
                vec[pos].second=0;
                pos++;
            }
        }
    }
}
