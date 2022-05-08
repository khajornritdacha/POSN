#include<bits/stdc++.h>
using namespace std;
int k,n,m,i,x,y,temp=0,countt=0,nf,np,tf=1,code=0,cl[10005]={0};
pair<int,int> lad[200005],a[200005];
queue <pair <int,int> > qq;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n >> m;
    for(i=0;i<m;i++){
        cin >> x >> y;
        lad[i] = {x,y};
        /*if(x==1)
            code = 1;*/
    }
    /*if(code == 0){
        cout << 1;
        return 0;
    }*/
    sort(lad,lad+m);

    for(i=0;i<m;i++){
        //cout << lad[i].first << lad[i].second << endl;
        if(temp!=lad[i].first){
            temp = lad[i].first;
            a[temp].first = i;
            a[temp].second++;
        }else{
            a[temp].second++;
        }
    }
        qq.push({1,k});
    /*for(i=0;i<countt;i++){
        printf("%d %d\n",a[i].first,a[i].second);
    }*/
    while(!qq.empty()){
            nf = qq.front().first;
            np = qq.front().second;
            //cout << nf << " " << np <<endl;
            qq.pop();
            if(np<=0){
                tf = max(nf,tf);
                continue;
            }
        for(i=a[nf].first;i<a[nf].first+a[nf].second;i++){
                qq.push({lad[i].second,np-1});
                cl[lad[i].second] = 1;
                tf = max(lad[i].second,tf);
               // cout << tf << endl;
            if(tf==n){
                cout << tf;
                return 0;
            }
        }
            if(cl[nf]==0&&np>0){
                qq.push({nf+1,np-1});
            }
    }
    cout << tf;
return 0;
}

