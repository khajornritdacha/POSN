#include<bits/stdc++.h>
using namespace std;
using lb = long double;
lb x,y;
string str;
lb cal(int r, int code){
    lb val = 0;
    for(int i=0; i<r; i++){
        val*=10;
        val+=str[i]-'0';
    }
    if(code)
        return sqrt(val*val/2);
    return val;
}
main(){
    cout << setprecision(3) << fixed;
    while(true){
        cin >> str;
        if(str == "*")
            break;
        char c1 = str[str.size()-2], c2 = str[str.size()-1];
        lb r;
        if('A' <= c1 and c1 <= 'Z')
            r = cal(str.size()-2, 1);
        else
            r = cal(str.size()-1, 0);
        if(c1 == 'N' or c2 == 'N')
            y+=r;
        if(c1 == 'S' or c2 == 'S')
            y-=r;
        if(c1 == 'E' or c2 == 'E')
            x+=r;
        if(c2 == 'W' or c2 == 'W')
            x-=r;
    }
    cout << x << " " << y << "\n" << sqrt(x*x+y*y);
}

