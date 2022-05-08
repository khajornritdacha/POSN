#include<bits/stdc++.h>
using namespace std;


main(){
    int A,B,C;
    cin >> A >> B >> C;
    if(A+B+C != 100){
        cout << "BUG";
        return 0;
    }

    int mx = max({A,B,C});

    if((A == mx and B == mx) or (A == mx and C == mx) or (B == mx and C == mx)){
        cout << "I DON'T KNOW";
        return 0;
    }

    if(A == mx)
        cout << "PAPER";
    else if(B == mx)
        cout << "SCISSORS";
    else
        cout << "ROCK";
}
