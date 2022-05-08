#include <bits/stdc++.h>
using namespace std;
long long dp[200][2][2];

int matrix(int level){
 //printf("=============level %d ====================\n",level);
 for(int a=0;a<=1;a++){
  for(int b=0;b<=1;b++){
   for(int c=0;c<=1;c++){
    dp[level+1][a][b]+=dp[level][a][c]*dp[level][c][b];
    dp[level+1][a][b]%=98765431;
   }
    //printf("%d %d==%d\n",a,b,dp[level+1][a][b]);
  }
 }
}
int main(){
 dp[0][0][0]=0;
 dp[0][0][1]=1;
 dp[0][1][0]=1;
 dp[0][1][1]=2;
 //pre-gen
 for(int a=0;a<=150;a++){
  matrix(a);
 }
 int t;
 scanf("%d",&t);
 while(t--){
  int ans[]={3,7};
  long long now;
  scanf("%lld",&now);
  int yao=0;
  long long nowmat[200][2][2];
  memset(nowmat,0,sizeof(nowmat));
  nowmat[0][0][0]=1;
  nowmat[0][0][1]=0;
  nowmat[0][1][0]=0;
  nowmat[0][1][1]=1;
  //now--;
  //printf("-%d-",nowmat[0][0][0]);
  while(now>0){
   yao++;
   //printf("%d ",now%2);
   if(now%2==1){
    for(int a=0;a<=1;a++){
     for(int b=0;b<=1;b++){
      long long chua=0;
      for(int c=0;c<=1;c++){
       nowmat[yao][a][b]+=nowmat[yao-1][a][c]*dp[yao-1][c][b];
       nowmat[yao][a][b]%=98765431;
      }
     }
    }
   }else{
    nowmat[yao][0][0]= nowmat[yao-1][0][0];
    nowmat[yao][0][1]= nowmat[yao-1][0][1];
    nowmat[yao][1][0]= nowmat[yao-1][1][0];
    nowmat[yao][1][1]= nowmat[yao-1][1][1];
   }
   now/=2;
  }
  printf("%lld\n",(nowmat[yao][1][0]+nowmat[yao][1][1])%98765431);
 }

}
