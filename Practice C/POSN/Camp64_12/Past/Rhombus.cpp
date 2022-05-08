#include<bits/stdc++.h>
using namespace std;
int n;
main(){
    cin >> n;
    for(int i=1; i<=(n+1)/2; i++){
        for(int j=1; j<=(n-1)/2; j++){
            if(j+i > (n+1)/2)
                cout << "*";
            else
                cout << " ";
        }
        for(int j=1; j<=(n+1)/2; j++){
            if(i>=j)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    for(int i=1; i<=(n-1)/2; i++){
        for(int j=1; j<=(n-1)/2; j++){
            if(j>i)
                cout << "*";
            else
                cout << " ";
        }
        for(int j=1; j<=(n+1)/2; j++){
            if(i+j <= (n+1)/2)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}
