#include<bits/stdc++.h>
using namespace std;
int id[10],sta[10],tot,nor,totstamp,n,K;
main(){
   for(int i=1; i<=3; i++){
        cin >> id[i] >> sta[i];
   }
   cin >> n >> K;
   for(int i=1; i<=n; i++){
        int x,y,num=0;
        cin >> x >> y;
        for(int j=1; j<=3; j++){
            if(x == id[j]){
                num = j;
                break;
            }
        }
        if(num){
            totstamp+=sta[num];
        }else{
            nor+=y;
        }
        tot+=y;
   }
   cout << tot << "\n" << nor << "\n" << totstamp+(nor/K);
}
