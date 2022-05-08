#include<bits/stdc++.h>
using namespace std;

const int N = 5e4+10;
using ll = long long;

int n,ans[10]; ///i v x l c

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int t = i;

        if(t >= 100){
            ans[4] += t/100;
            t %= 100;
        }

        if(t >= 90){
            ans[2]++;
            ans[4]++;
            t -= 90;
        }

        if(t >= 50){
            ans[3]++;
            t -= 50;
        }

        if(t >= 40){
            ans[2]++;
            ans[3]++;
            t -= 40;
        }

        if(t >= 10){
            ans[2] += t/10;
            t %= 10;
        }

        if(t >= 9){
            ans[0]++;
            ans[2]++;
            t -= 9;
        }

        if(t >= 5){
            ans[1]++;
            t -= 5;
        }

        if(t >= 4){
            ans[0]++;
            ans[1]++;
            t -= 4;
        }

        if(t >= 1){
            //cout << t << "\n";
            ans[0] += t;
        }
    }

    for(int i : {0, 1, 2, 3, 4}) cout << ans[i] << " ";
    return 0;
}
