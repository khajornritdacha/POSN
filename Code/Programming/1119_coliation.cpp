#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
long long all,qs[300010];
int n,a[300010],pos[300010];
vector<pi> vec;

int bi(int val, int base,int low){
    int mid,l,r=n-1;
    if(low==-1){
        l=0;
    }else{
        l=low;
    }
    while(l<=r){
        mid=(l+r)/2;
        if(qs[mid]-base>=val){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return mid;
}

main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        all+=a[i];
        vec.emplace_back(a[i],i);
    }
    sort(vec.rbegin(),vec.rend());
    qs[0]=vec[0].first;
    pos[vec[0].second]=0;
    for(int i=1; i<n; i++){
        qs[i]=qs[i-1]+vec[i].first;
        pos[vec[i].second]=i;
    }
    for(int i=0; i<n; i++){
        cout << qs[i] << " ";
    }
    cout << "\n---------------------------\n";
    for(int i=1; i<=n; i++){
        int want=(all/2)+1;
        int k=bi(want-a[i],0,-1);
        int ans=k+1;
        cout << want-a[i] << " ";
        //cout << k << " " << pos[k] << " " << pos[i] << " ";
        if(k>=pos[i]){
            int k2=bi(qs[k]-a[i],qs[k+1],k+1);
            ans--;
            ans+=(k2-k);
            cout << k2 << " ";
        }
        cout << ans << "\n";
    }
}




