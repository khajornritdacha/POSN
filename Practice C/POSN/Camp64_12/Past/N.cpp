#include<bits/stdc++.h>
using namespace std;
int n;
void de(int &x){
    x = ((x-1)%10+10)%10;
}
void in(int &x){
    x = (x+1)%10;
}
main(){
    cin >> n;
    int l = n%10;
    int r = (((2*n-1)%10)+(n-1))%10;
    int mid = (n+1)%10;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j == 1){
                cout << l;
                de(l);
            }else if(j == n){
                cout << r;
                de(r);
            }else if(i!=1 and i!=n and i == j){
                cout << mid;
                in(mid);
            }else{
                cout << " ";
            }
            cout << " ";
        }
        cout << "\n";
    }
}
