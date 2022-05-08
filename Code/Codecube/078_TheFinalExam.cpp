#include<bits/stdc++.h>
using namespace std;

int K,sum,a[10];

main(){
    cin >> K;
    for(int i=1; i<=5; i++){
        cin >> a[i];
        sum += a[i];
    }

    if(sum == K){
        for(int i=1; i<=5; i++)
            cout << a[i] << " ";
    }else{
        for(int i=1; i<=5; i++){
            if(sum-a[i] == K){
                a[i] = 0;

                for(int i=1; i<=5; i++){
                    cout << a[i] << " ";
                }
                return 0;

            }
        }
        cout << "-1";
    }

}
