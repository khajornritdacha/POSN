#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 1e5+10;
struct book{
    int type,price,amount;
};
book bk[N];
int tys[N],id,ty,pri,am;

main(){
    while(true){
        cin >> id;
        if(id == 0)
            break;
        cin >> ty >> pri >> am;
        bk[id].type = ty;
        bk[id].price = pri;
        bk[id].amount += am;
        tys[ty]+=am;
    }
    for(int i=1; i<=1e5; i++){
        if(bk[i].amount != 0){
            cout << i << " " << bk[i].type << " " << bk[i].price << " " << bk[i].amount << "\n";
        }
    }
    for(int i=1; i<=1e5; i++){
        if(tys[i] != 0){
            cout << "Type " << i << " " << tys[i] << "\n";
        }
    }
}
