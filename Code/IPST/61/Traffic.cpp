#include <bits/stdc++.h>
#include "traffic.h"
using namespace std;

// void traffic_init(int *NN, int *KK){
//     scanf("%d %d", NN, KK);
// }

// int traffic_query(int x1, int y1, int x2, int y2){
//     printf("Input : (%d, %d), (%d, %d)\n", x1, y1, x2, y2);
//     int dis; scanf("%d", &dis);
//     return dis;
// }

// void traffic_report(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
//     printf("REPORT\n");
//     printf("(%d, %d), (%d, %d)\n", ax1, ay1, ax2, ay2);
//     printf("(%d, %d), (%d, %d)\n", bx1, by1, bx2, by2);
// }

int bsx(int l, int r, int y){
    int ans = -1, ql = l-1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(traffic_query(ql, y, mid, y) > mid-ql){
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return ans;
}

int bsy(int l, int r, int x){
    int ans = -1, ql = l-1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(traffic_query(x, ql, x, mid) > mid-ql){
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return ans;
}


int main(void){
    int n, K;
    traffic_init(&n, &K);
    int an[4][2] = {}, cnt = 0;

    for(int y = 1; y <= n; y++){
        int res = traffic_query(1, y, n, y);
        if(res != n-1){
            int ans = bsx(2, n, y);
            an[0][cnt] = ans-1, an[1][cnt] = y, an[2][cnt] = ans, an[3][cnt] = y;
            cnt++;

            if(res == n+1){
                int ans2 = bsx(ans+1, n, y);
                an[0][cnt] = ans2-1, an[1][cnt] = y, an[2][cnt] = ans2, an[3][cnt] = y;
                cnt++;
            }
        }
    }    

    for(int x = 1; x <= n; x++){
        int res = traffic_query(x, 1, x, n);
        if(res != n-1){
            int ans = bsy(2, n, x);
            an[0][cnt] = x, an[1][cnt] = ans-1, an[2][cnt] = x, an[3][cnt] = ans;
            cnt++;

            if(res == n+1){
                int ans2 = bsy(ans+1, n, x);
                an[0][cnt] = x, an[1][cnt] = ans2-1, an[2][cnt] = x, an[3][cnt] = ans2;
                cnt++;
            }
        }
    }

    traffic_report(an[0][0], an[1][0], an[2][0], an[3][0], an[0][1], an[1][1], an[2][1], an[3][1]);

    return 0;
}