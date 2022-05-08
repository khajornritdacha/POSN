#include<bits/stdc++.h>
using namespace std;
int n,day[]={6,2,6,6,4,5,10},h[10];
char name[10][100] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
main(){
    cin >> n;
    int d = 0;
    for(int i=0; i<7; i++)
        h[i] = day[i];
    for(int i=1; i<=n; i++){
        int now;
        cin >> now;
        while(true){
            if(now <= h[d]){
                h[d] -= now;
                cout << name[d] << "\n";
                break;
            }else{
                now -= h[d];
                h[d++] = 0;
                if(d == 7){
                    d = 0;
                    for(int j=0; j<7; j++)
                        h[j] = day[j];
                }
            }
        }
    }
}
