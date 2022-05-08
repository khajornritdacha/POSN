#include<bits/stdc++.h>
using namespace std;

void prd(int x, int code=0);
void prl(int x, int code=0);

main(){
    prd(5);
    prl(10);
}

void prd(int x, int code){
    if(!code)
        prl(x, 1);
    for(int i=0; i<x; i++)
        cout << '*';
    cout << "\n";
    if(!code)
        prl(x, 1);
}

void prl(int x, int code){
    for(int i=0; i<x; i++)
        cout << "-";
    cout << "\n";
    if(!code)
        prd(x, 1);
    for(int i=0; i<x; i++)
        cout << "-";
    cout << "\n";
}
