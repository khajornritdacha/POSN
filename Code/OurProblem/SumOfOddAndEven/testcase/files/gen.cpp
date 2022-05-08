#include <iostream>
#include "testlib.h"
using namespace std;


int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    int n = rnd.next((N+1)/2, N);
    for(int i = 1; i <= n; i++){
        int x, cnt = 0;
        do{
            cnt++;
            x = rnd.next(-100, 100);

            if(cnt > 1000){
                x = -5;
            }
        } while(x == 0);
         
        printf("%d\n", x);
    }
    printf("0\n");
    return 0;
}