#include<bits/stdc++.h>
using namespace std;

int A,B,C;

main(){
    cin >> A >> B >> C;
    for(int a=1; a<=A; a++){
        if(A%a != 0) continue;
        int c = A/a;
        for(int b=-100; b<=100; b++){
            if(b == 0) continue;
            if(C%b != 0) continue;
            int d = C/b;
            if(a*c == A and a*d+b*c == B and b*d == C){
                cout << a << " " << b << " " << c << " " << d << "\n";
                return 0;
            }
        }
    }
    cout << "No Solution";
}
