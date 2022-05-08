#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
using tu=tuple<int,int,int>;
int r,c,ans,a[105][105];
bool visit[105][105][1000];
queue<tu> qq;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<=2;i++)
        if(a[(r-1)/2+i][1]!=0){
            qq.emplace((r-1)/2+i,1,1);
        }
    int pr[]={-1,-1,0,0,1,1},pc[10];
    while(!qq.empty()){
        int nowr,nowc,cou;
        tie(nowr,nowc,cou)=qq.front();
        qq.pop();
        visit[nowr][nowc][cou]=true;
        if(nowr==(r-1)/2+1&&nowc==c){
            ans=cou;
            break;
        }
        if(nowr%2==1){
            pc[0]=0;
            pc[1]=1;
            pc[2]=-1;
            pc[3]=1;
            pc[4]=0;
            pc[5]=1;
        }else{
            pc[0]=-1;
            pc[1]=0;
            pc[2]=-1;
            pc[3]=1;
            pc[4]=-1;
            pc[5]=0;
        }
        for(int i=0;i<6;i++){
            int nr=nowr+pr[i];
            int nc=nowc+pc[i];
            if(nr<1||nc<1||nr>r||nc>c)
                continue;
            if(a[nr][nc]==0)
                continue;
            if((cou+1)%a[nr][nc])
                continue;
            if(visit[nr][nc][cou+1])
                continue;
            qq.emplace(nr,nc,cou+1);
            visit[nr][nc][cou+1]=true;
        }
    }
    cout << ans;
}

