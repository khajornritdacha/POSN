#include<bits/stdc++.h>
using namespace std;
int k,m,n,i,j,minl=INT_MAX,mins=INT_MAX,ansl,anss,dayl,days,day,daytemp;
int main(){
    scanf("%d",&k);
    scanf("%d %d",&m,&n);
    if(m==0&&n>0){
        printf("0 %d",k);
    }else if(m>0&&n==0){
        for(i=1;i<=k;i++){
            if(m/(i*6)<mins){
                mins = m/(i*6);
                ansl = i;
            }
        }
        printf("%d %d",ansl,k-ansl);
    }else{
        for(i=1;i<k;i++){
            j = k-i;
            dayl = m/(i*6);
            days = n/(j*10);
            if(dayl>days)
                daytemp = dayl;
            else
                daytemp = days;
            if(daytemp<minl){
                minl = daytemp;
                ansl = i;
                anss = j;
        }
        }
        printf("%d %d",ansl,anss);
    }
    return 0;
}
