#include<bits/stdc++.h>
using namespace std;
char par[500],temp[500],temprev[500],ans=0,x;
int n,cou=0,ns;
main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> par;
    n = strlen(par);
    for(int i=0;i<n;i++){
        if(par[i]>='a'&&par[i]<='z')
            par[i]-=32;
    }
    for(int i=n-1;i>=0;i--){
        temprev[i] = par[cou];
        temp[i] = par[i];
        cou++;
    }
    cou = 0;
    /*for(int i=0;i<n;i++){
    cout << temp[i];
    }
    cout << endl;
    for(int i=0;i<n;i++){
    cout << temprev[i];
    }
    cout << endl;*/
    for(int i=0;i<n;i++){
        if(temp[i]!=temprev[i]){
            cout << "No";
            return 0;
        }
    }
    ans = 1;
    for(int i=0;i<n;i++){
        temp[i] = 0;
        temprev[i] = 0;
    }
        ns = n/2;
        cou = ns-1;
        for(int i=0;i<ns;i++){
            temp[i] = par[i];
            temprev[i] = par[cou];
            cou--;
        }
        for(int i=0;i<ns;i++){
            if(temp[i]!=temprev[i]){
                cout << "Palindrome";
                return 0;
            }
        }
        if(n%2!=0){
            x = 1;
        }
        cou = n-1;
        for(int i=ns+x;i<n;i++){
            temp[i] = par[i];
            temprev[i] = par[cou];
            cou--;
        }
        for(int i=ns+x;i<n;i++){
            if(temp[i]!=temprev[i]){
                cout << "Palindrome";
                return 0;
            }
        }
        cout << "Double Palindrome";
        return 0;
}
