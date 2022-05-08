#include<bits/stdc++.h>
#define int long long
using namespace std;
main(){
    FILE *fi,*fo;
    fi = fopen("input.txt","r");
    fo = fopen("output.txt","w");
    int n;
    fscanf(fi,"%lld",&n);
    int m=n;
    while(n--){
        //cout << m-n << endl;
        fprintf(fo,"Case #%lld: ",m-n);
        int node,gallon;
        fscanf(fi,"%lld%lld",&node,&gallon);
        long long money[node+5];
        for(int i=0;i<node;i++){
            fscanf(fi,"%lld",&money[i]);
        }
        int dp[2][gallon+5];
        for(int i=0;i<2;i++){
            for(int j=0;j<=gallon+2;j++){
                dp[i][j]=1e18;
            }
        }
        for(int i=0;i<=gallon;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<node;i++){
            for(int j=0;j<=gallon;j++){
                dp[(i)%2][j]=dp[(i-1)%2][j+1];
            }
            if(money[i]!=0){
                for(int j=0;j<gallon;j++){
                    dp[i%2][gallon]=min(dp[i%2][j]+money[i],dp[i%2][gallon]);
                }
            }
        }
        int minn=1e18;
        for(int i=0;i<gallon;i++){
           minn=min(minn,dp[(node-1)%2][i]);
        }
        if(minn==1e18){
            fprintf(fo,"-1\n");
        }
        else{
            fprintf(fo,"%lld\n",minn);
        }
    }
}
