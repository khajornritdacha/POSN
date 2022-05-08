#include<stdio.h>


struct{
    int first,second;
}typedef DATA;

int pos=0,pm=0,n=5;
float x[1010],y[1010],mx=0,mn=1e9;
DATA ans[1010],ans2[1010];

main(){
    for(int i=1; i<=n; i++){
        scanf("%f %f", &x[i], &y[i]);
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            float now = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            if(now > mx){
                mx = now;
                pos = 0;
            }
            if(now == mx){
                DATA tmp;
                tmp.first = i;
                tmp.second = j;
                ans[pos++] = tmp;
            }
            if(now < mn){
                mn = now;
                pm = 0;
            }
            if(now == mn){
                DATA tmp;
                tmp.first = i;
                tmp.second = j;
                ans2[pm++] = tmp;
            }
        }
    }
    printf("Max is\n");
    for(int i=0; i<pos; i++){
        printf("(%.2f,%.2f)-(%.2f,%.2f)\n", x[ans[i].first], y[ans[i].first], x[ans[i].second], y[ans[i].second]);
    }
    printf("\nMin is\n");
    for(int i=0; i<pm; i++){
        printf("(%.2f,%.2f)-(%.2f,%.2f)\n", x[ans2[i].first], y[ans2[i].first], x[ans2[i].second], y[ans2[i].second]);
    }
}
