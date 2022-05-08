#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,ans = pow(2,31);
vector<int> edit,a;
bool zero;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        a.emplace_back(x);
    }
    int low=0,high = pow(2,31),kong,cou;
    while(low<=high){
        int mid = (low+high)/2;
        cou = 0;
        kong = mid;
        vector<int> temp;
            for(int i=0;i<a.size();i++){
                if(a[i]>kong){
                    temp.emplace_back(a[i]);
                    //cout << a[i] << " ";
                    cou++;
                    if(temp.size()>=2&&temp[temp.size()-1]==temp[temp.size()-2]){
                        cou-=2;
                        //cout << temp[temp.size()-1] << " ";
                    }
                }
            }
        //cout << cou << "\n";
        if(cou!=0){
            low = mid+1;
            a = temp;
        }else{
            ans = min(ans,kong);
            high = mid-1;
        }
    }
    cout << ans;
}
