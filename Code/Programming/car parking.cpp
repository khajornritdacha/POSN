#include<bits/stdc++.h>
using namespace std;
int a[105][105],n,m,t,ans[105];
bool visit[105][105];
int temp[105];
deque < pair<int,int> > deq;
main(){
    scanf("%d %d %d",&m,&n,&t);
    for(int i=1;i<=t;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    temp[0]=n;
    deq.push_front({0,n});
    while(!deq.empty()){
        int row = deq.front().first;
        int col = deq.front().second;
        deq.pop_front();
        if(visit[row][col]==true)
            continue;
        visit[row][col] = true;
        temp[row] = col;
        if(a[row][col]==0&row==t){
            break;
        }
        if(a[row+1][col-1]==0&&row+1<=t&&col-1>=1&&col-1<=m){
            deq.push_front({row+1,col-1});
        }
        if(a[row+1][col]==0&&row+1<=t&&col>=1&&col<=m){
            deq.push_front({row+1,col});
        }
        if(a[row+1][col+1]==0&&row+1<=t&&col+1>=1&&col+1<=m){
            deq.push_front({row+1,col+1});
        }
    }
     for(int i=1;i<=t;i++){
        if(temp[i] > temp[i-1]){
            ans[i] = 2;
        }else if(temp[i] == temp[i-1]){
            ans[i] = 3;
        }if(temp[i] < temp[i-1]){
            ans[i] = 1;
        }
    }
    for(int i=1;i<=t;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
