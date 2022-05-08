#include<bits/stdc++.h>
using namespace std;
int m,n;
main(){
    cin >> m >> n;
    int a = 1;
    int b = 1;
    int sa = 1;
    int sb = 1;
    for(int i=2; abs(a)!=abs(m); i++){
        a*=-1;
        if(i%2)
            a+=2;
        else
            a-=2;
        sa+=a;
    }
    for(int i=2; abs(b)!=abs(n); i++){
        b*=-2;
        sb+=b;
    }
    cout << sa*sb;
}
