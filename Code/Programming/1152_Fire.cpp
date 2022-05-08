#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
queue <  pii  > qq;
int n,a[1005][1005],maxx[1000005],maxt,sum,t[1005][1005];
bool visit[1005][1005];
priority_queue < pii > pq;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    qq.push({1,1});
    t[1][1] = 1;
    while(!qq.empty()){
        int row = qq.front().first;
        int col = qq.front().second;
        visit[row][col] = true;
        pq.emplace(a[row][col],t[row][col]);
        maxt = max(maxt,t[row][col]);
        qq.pop();
        int pr[]={-1,0,0,1},pc[]={0,-1,1,0};
        for(int i=0;i<4;i++){
            int nr = row+pr[i];
            int nc = col+pc[i];
            if(nr<1||nc<1||nr>n||nc>n)
                continue;
            if(visit[nr][nc]==true)
                continue;
            t[nr][nc] = t[row][col]+1;
            qq.push({nr,nc});
            visit[nr][nc]=true;
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //maxx[t[i][j]] = max(a[i][j],maxx[t[i][j]]);
            //maxt = max(maxt,t[i][j]);
            //cout << t[i][j] << " ";
        }
        //cout << "\n";
    }*/
    //cout << maxt << "\n";
    /*for(int i=2;i<=maxt;i++){
       // cout << maxx[i] << " ";
        sum+=maxx[i];
    }*/
    int cnt=1;
    while(!pq.empty()){
        int va = pq.top().first,pos = pq.top().second;
        pq.pop();
        for(int i=pos;i>=2;i--){
            if(maxx[i]==0){
                maxx[i] = va;
                cnt++;
                break;
            }
        }
        if(cnt==maxt){
            //cout << "xxx";
            break;
        }
    }
    for(int i=2;i<=maxt;i++){
        sum+=maxx[i];
        //cout << maxx[i] << " ";
    }
    cout << sum;
}
