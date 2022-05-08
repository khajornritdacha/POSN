#include<bits/stdc++.h>
using namespace std;
stack <char> par;
string input[100010];
int n,cou=0,ans[100];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> input[i];
        cou=0;
                //cout << input[i].size() << endl;
        while(!par.empty()){
            par.pop();
        }
        //cout << input[i] << endl;
        /*cout << input.size();*/
        /*if((input.size())%2!=0){
            cout << "no" << endl;
            continue;
        }*/
        for(int j=0;j<input[i].size();j++){
           /*cout << input[i][j] << " " << j <<" ";
            if(!par.empty())
                cout << par.top() << endl;*/
            if(input[i][j]=='('||input[i][j]=='{'||input[i][j]=='['){
                par.push(input[i][j]);
                //cout << "'" << par.top() << "'" << endl ;
            }else{
            if(!par.empty()){
             if(input[i][j]==')'&&par.top()=='('){
                par.pop();
                //cout << 111;
            }else if(input[i][j]=='}'&&par.top()=='{'){
                par.pop();

            }else if(input[i][j]==']'&&par.top()=='['){
                par.pop();

            }else{
                //cout << "no" << endl;
                //cout << ')' << endl;
                ans[i] = 1;
                cou = 1;
                break;
            }
            }else if(par.empty()){
                ans[i] = 1;
                cou = 1;
                break;
            }
        }
        }
        if(cou==0&&par.empty()){
            ans[i] = 2;
        }
        if(!par.empty()){
            ans[i] = 1;
        }
    }
    for(int i=0;i<n;i++){
        //cout << ans[i] << endl;
        if(ans[i]==2)
            cout << "yes" << endl;
        else if(ans[i]==1)
            cout << "no" << endl;
    }
    return 0;
}
