#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int n,k,A,mx,pos,ans;
vector<int> vec;
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> A;
    int chua=0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        chua+=x;
        vec.push_back(chua);
    }
    //int l=1,r=chua,mid,pa=1e9,temp=0;
    for(int mid=1;mid<=chua;mid++){
    int pa=1e9,temp=0;
    for(int i=0;i<k;i++){
        if(mid+(A*i)>chua) break;
        int pos=lower_bound(vec.begin(),vec.end(),mid+(A*i))-vec.begin();
        if(pos!=pa){
            temp++;
            pa=pos;
        }
    }
        if(temp>mx){
            mx=temp;
            ans=mid;
        }else if(temp==mx){
            ans=min(ans,mid);
        }
    }
   /* while(l<=r){
        temp=0,pa=1e9;
        mid = (l+r)/2;
        //cout << mid << " ";
        for(int i=0;i<k;i++){
            if(mid+(A*i)>chua) break;
            int pos=lower_bound(vec.begin(),vec.end(),mid+(A*i))-vec.begin();
            if(pos!=pa){
                temp++;
                pa=pos;
            }
            //cout << pos << " ";
        }
        if(temp>mx){
            mx = temp;
            ans = mid;
            l = mid+1;
        }else if(temp==mx){
            ans = min(ans,mid);
            l = mid+1;
        }else{
            r = mid-1;
        }
        //cout << "\n";
    }*/
    cout << ans << " " << mx;
}
