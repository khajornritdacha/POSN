#include<bits/stdc++.h>
using namespace std;
int t,d[10],tmp[10];
string str;
void ffw(){
    d[1]=tmp[4], d[2]=tmp[1], d[3]=tmp[3], d[4]=tmp[6], d[5]=tmp[5], d[6]=tmp[2];
}
void fbw(){
    d[1]=tmp[2], d[2]=tmp[6], d[3]=tmp[3], d[4]=tmp[1], d[5]=tmp[5], d[6]=tmp[4];
}
void flt(){
    d[1]=tmp[5], d[2]=tmp[2], d[3]=tmp[1], d[4]=tmp[4], d[5]=tmp[6], d[6]=tmp[3];
}
void frl(){
    d[1]=tmp[3], d[2]=tmp[2], d[3]=tmp[6], d[4]=tmp[4], d[5]=tmp[1], d[6]=tmp[5];
}
void fcw(){
    d[1]=tmp[1], d[2]=tmp[5], d[3]=tmp[2], d[4]=tmp[3], d[5]=tmp[4], d[6]=tmp[6];
}
void fct(){
    d[1]=tmp[1], d[2]=tmp[3], d[3]=tmp[4], d[4]=tmp[5], d[5]=tmp[2], d[6]=tmp[6];
}
main(){
    cin >> t;
    while(t--){
        cin >> str;
        for(int i=1; i<=6; i++)
            d[i] = i;
        d[4] = 5, d[5] = 4;
        for(int i=0; i<str.size(); i++){
            for(int j=1; j<=6; j++)
                tmp[j] = d[j];
            if(str[i] == 'F')
                ffw();
            else if(str[i] == 'B')
                fbw();
            else if(str[i] == 'L')
                flt();
            else if(str[i] == 'R')
                frl();
            else if(str[i] == 'C')
                fcw();
            else
                fct();
        }
        cout << d[2] << " ";
    }
}
