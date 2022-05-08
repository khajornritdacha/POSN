#include<bits/stdc++.h>
using namespace std;
int lca[10],i,n,c[10],temp,ans=0;
//lca[0] = ‡»…‡§È° 1/2 °ÈÕπ
//lca[1] = ‡»…‡§È° 1/4 °ÈÕπ
//lca[2] = ‡»…‡§È° 1/8 °ÈÕπ
//lca[5] = ‡»…‡§È° 3/4 °ÈÕπ
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin >> temp;
            c[j] += temp;
        }
    }
    ans+=c[0];
    ans+=c[1];
    lca[1]+=c[1]; //‡»…‡§È° 1/4
    if(c[2]!=0){
        for(i=1;i<=c[2];i++){
            if(lca[0]>0){
                lca[0]-=1;
            }else{
                ans+=1;
                lca[0]+=1;
            }
        }
    }
    if(c[3]!=0){
       for(i=1;i<=c[3];i++){
        if(lca[1]>0){
            lca[1]-=1;
        }else if(lca[0]>0){
            lca[0]-=1;
            lca[1]+=1;
        }else if(lca[5]>0){
            lca[5]-=1;
            lca[0]+=1;
        }else{
            lca[5]+=1;
            ans+=1;
        }
       }
    }
    if(c[4]!=0){
        for(i=1;i<=c[4];i++){
        if(lca[2]>0){
            lca[2]-=1;
        }
        else if(lca[1]>0){
            lca[1]-=1;
            lca[2]+=1;
        }else if(lca[0]>0){
            lca[0]-=1;
            lca[1]+=1;
            lca[2]+=1;
        }else if(lca[5]>0){
            lca[2]+=1;
            lca[0]+=1;
            lca[5]-=1;
        }else{
            lca[5]+=1;
            lca[2]+=1;
            ans+=1;
        }
        }
    }

    /*for(int j=0;j<5;j++){
            cout << c[j] << " ";
        }*/
    cout << ans;
    return 0;
}
