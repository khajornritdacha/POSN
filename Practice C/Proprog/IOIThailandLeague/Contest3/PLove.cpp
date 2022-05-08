#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
char pt[10][5][5] = {   {{'#',' ',' '}, {'#',' ',' '}, {'#','#','#'}},
                        {{'#','#','#'},{'#',' ','#'},{'#','#','#'}},
                        {{'#',' ','#'},{'#',' ','#'},{' ','#',' '},},
                        {{'#','#','#'},{'#','#',' '},{'#','#','#'}}
                    };
main(){
    for(int t=0; t<4; t++){
        int pos;
        char c;
        cin >> c;
        if(c == 'L')
            pos = 0;
        else if(c == 'O')
            pos = 1;
        else if(c == 'V')
            pos = 2;
        else
            pos = 3;
        //cout << pos << "\n";
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cout << pt[pos][i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
