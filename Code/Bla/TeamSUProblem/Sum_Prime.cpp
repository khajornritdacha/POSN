#include<bits/stdc++.h>
using namespace std;
int n;
bool isprime(int i){
    if(i==2) return 1;
    if(i%2==0||i<2) return 0;
    int k=sqrt(i);
    for(int j=3; j<=k; j+=2){
        if(i%j==0)
            return 0;
    }
    return 1;
}
main(){
    cin >> n;
    if(n<=3){ cout << -1; return 0;}
    if(n==4){ cout << "2 2"; return 0;}
    if(n%2==1){
        int temp=n-2;
        if(temp%2==0||temp<2){ cout << -1; return 0; }
        int k=sqrt(temp);
        for(int i=3; i<=k; i+=2){
            if(temp%i==0){
                cout << -1;
                return 0;
            }
        }
        cout << "2 " << temp;
        return 0;
    }else{
        for(int i=3; i<=n; i+=2){
            if(isprime(i)&&isprime(n-i)){
                cout << i << " " << n-i;
                return 0;
            }
        }
    }
}
