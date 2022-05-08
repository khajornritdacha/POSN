#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int n,K,M[N],F[N];
bool ok = true;

main(){
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> M[i] >> F[i];
    }

    for(int i=1; i<=n; i++){
        int k=1;
        while(k <= K and F[i] < M[i]){
            if(F[i+k] >= M[i]-F[i]){
                F[i+k]-=M[i]-F[i];
                F[i] = M[i];
                break;
            }else{
                F[i] += F[i+k];
                F[i+k] = 0;
            }
            k++;
        }
        k = 1;
        while(k <= K and M[i] < F[i]){
            if(M[i+k] >= F[i]-M[i]){
                M[i+k] -= F[i]-M[i];
                M[i] = F[i];
            }else{
                M[i] += M[i+k];
                M[i+k] = 0;
            }
            k++;
        }

        if(M[i] != F[i])
            ok = false;
    }

    if(ok)
        cout << "YES";
    else
        cout << "NO";
}
