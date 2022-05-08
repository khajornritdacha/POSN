#include <bits/stdc++.h>
#include "combo.h"

using namespace std;

///https://oj.uz/submissions?problem=IOI18_combo

/*int press(string p){
    cout << p << "\n";
    int x; cin >> x; return x;
}*/

string guess_sequence(int N){
    string str;
    vector<char> a = {'A', 'B', 'X', 'Y'};

    if(press("AB") == 0){ ///either x or y
        if(press("X") == 1){
            str += 'X';
            a.erase(a.begin()+2);
        }else{
            str += 'Y';
            a.erase(a.begin()+3);
        }
    }else{ ///either a or b
        if(press("A") == 1){
            str += 'A';
            a.erase(a.begin());
        }else{
            str += 'B';
            a.erase(a.begin()+1);
        }
    }

    /*cout << "\n";
    for(char x : a) cout << x << " ";
    cout << "\n";*/

    for(int i = 2; i < N; i++){
        string tmp = str + a[1] + str + a[2] + a[0] + str + a[2] + a[1] + str + a[2] + a[2];
        int res = press(tmp);

        if(res == str.size()){ ///got nothing new
            str += a[0];
        }else if(res == str.size()+1){
            str += a[1];
        }else{
            str += a[2];
        }
    }

    if(str.size() < N){
        if(press(str+a[0]) == N){
            str += a[0];
        }else if(press(str+a[1]) == N){
            str += a[1];
        }else{
            str += a[2];
        }
    }

    return str;
}

/*
int main(void){
    int n; cin >> n;
    cout << guess_sequence(n) << "\n";
    return 0;
}
*/

