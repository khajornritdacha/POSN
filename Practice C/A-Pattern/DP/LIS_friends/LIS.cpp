#include<bits/stdc++.h>
using namespace std;
vector<int> vec,bt,ipt(10005),P(10005);
stack<int> st;
int n;
///longest increasing subsequence
main()
{
   cin >> n;
   for(int i=1;i<=n;i++){
        cin >> ipt[i];
        int k = lower_bound(vec.begin(),vec.end(),ipt[i])-vec.begin();
        if(k==vec.size()){
            vec.push_back(ipt[i]);
            bt.push_back(i);
        }
        else{
            vec[k] = ipt[i];
            bt[k] = i;
        }
        if(k-1>=0)
            P[i] = bt[k-1];
   }
   cout << "Length: " << vec.size() << "\n";
   int track = bt.back();
   while(track!=0){
        st.push(ipt[track]);
        track = P[track];
   }
    cout << "LIS: ";
   while(!st.empty()){
        cout << st.top() << " ";o
        st.pop();
   }
}
/*
9
-7 10 11 9 2 3 8 8 1
*/
