#include<bits/stdc++.h>
#define int long long
using namespace std;
using lb = long double;
lb Lc,sold,Rev,Spend,prof,ansprof=1e9;
int ansprint, ansprice,C;
main(){
    cout << setprecision(2) << fixed;
    cin >> C;
    for(int price = 74; price <= 144; price++){
        for(int print = 1000; print <= 15000; print+=500){
            int dis = (print-1000)/500;
            Lc = print*(100-dis);
            sold = (100-(0.8569*pow(M_E, (lb)0.09*(price-100))))*print/100;
            Rev = sold*price;
            Spend = C+Lc;
            prof = Rev-Spend;
            if(prof > 0.000001 and ansprof-prof > 0.000001){
                ansprint = print;
                ansprice = price;
                ansprof = prof;
            }
        }
    }
    cout << ansprint << "\n" << ansprice << "\n";
    cout << ansprof << "\n";
}
