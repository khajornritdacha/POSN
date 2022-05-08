#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,x,y,low,high,mid,ans=LLONG_MAX,temp=LLONG_MAX;
queue <long long> a,b;
priority_queue < pair<long long,long long> > pq;
long long binary( priority_queue < pair<long long,long long> > pq,int middle){
    priority_queue <long long>  bi,tt;
    long long sum=0,s,tmin;
    for(int i=0;i<middle;i++){
        sum+=pq.top().first;
        s = pq.top().second;
        bi.push(s);
        tmin = bi.top();
        pq.pop();
    }
    //cout << tmin << endl;
    while(!pq.empty()){
        s = pq.top().second;
        tt.push(s);
        pq.pop();
    }
    while(!tt.empty()){
        //cout << tmin << endl;
        sum+=(tmin+tt.top());
        s = tt.top();
        if(s*-1<tmin*-1)
            tmin = s;
        tt.pop();
    }
    return sum*-1;
}
main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        a.push(x);
    }
    for(int i=0;i<n;i++){
        cin >> y;
        b.push(y);
    }
    for(int i=0;i<n;i++){
        x = a.front();
        y = b.front();
        pq.push({x*-1,y*-1});
        a.pop();
        b.pop();
        //cout << x << " " << y << endl;
    }
    low = 1;
    high = n;
    while(low<=high){
        mid = (low+high)/2;
        int lmid = (mid+low-1)/2;
        int hmid = (mid+high+1)/2;
        int code = 0;
        if(binary(pq,mid)<ans)
            ans = binary(pq,mid);
       // cout << ans << endl;
       // cout << low << " " << mid << " " << high << endl;
        if(binary(pq,low)<ans){
            high = mid-1;
            ans = binary(pq,low);
            code = 1;
        }
        if(binary(pq,high)<ans){
            low = mid+1;
            ans = binary(pq,high);
            code = 1;
        }
        if(code == 0){
            low = lmid+1;
            high = hmid-1;
        }
    }/*
    for(int i=1;i<=n;i++){
        if(binary(pq,i)<ans){
            ans = binary(pq,i);
        }
    }*/
    cout << ans;
    //cout << endl << 'xxx' << endl << binary(pq,2);
    return 0;
}
/*
6
2 1 7 8 9 7
10 11 3 4 2 3
*/
