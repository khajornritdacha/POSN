#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
char c[N];
int mx,ans[3],n;
main(){
    cin >> n;
    cin >> c+1;
    for(int i=1; i<=n; i++){
        if(i%3 == 1 and c[i] == 'A')
            ans[0]++;
        else if(i%3 == 2 and c[i] == 'B')
            ans[0]++;
        else if(i%3 == 0 and c[i] == 'C')
            ans[0]++;

        if(i%2 == 1)
            ans[1]+=(c[i] == 'B');
        else{
            if((i/2)%2 == 1 and c[i] == 'A')
                ans[1]++;
            else if((i/2)%2 == 0 and c[i] == 'C')
                ans[1]++;
        }

        if(((i+1)/2)%3 == 1 and c[i] == 'C')
            ans[2]++;
        else if(((i+1)/2)%3 == 2 and c[i] == 'A')
            ans[2]++;
        else if(((i+1)/2)%3 == 0 and c[i] == 'B')
            ans[2]++;
        //cout << "I : " << i << " " << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    }
    mx = *max_element(ans, ans+3);
    cout << mx << "\n";
    if(ans[0] == mx)
        cout << "Adrian\n";
    if(ans[1] == mx)
        cout << "Bruno\n";
    if(ans[2] == mx)
        cout << "Goran\n";
}
