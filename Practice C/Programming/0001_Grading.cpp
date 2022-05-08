#include<bits/stdc++.h>
using namespace std;
int x,y,z,score;
main(){
    scanf("%d%d%d",&x,&y,&z);
    score = x+y+z;
    if(score >=80){
        printf("A\n");
    }else if(score >=75){
        printf("B+");
    }else if(score >= 70){
        printf("B");
    }else if(score >= 65){
        printf("C+");
    }else if(score >= 60){
        printf("C");
    }else if(score >= 55){
        printf("D+");
    }else if(score >= 50){
        printf("D");
    }else{
        printf("F");
    }
}
