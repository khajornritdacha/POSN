#include <bits/stdc++.h>
#include "rescuelib.h"
using namespace std;

void cal1(int R, int C, int tr, int tc, int d1, int d2, int &ar, int &ac){
    ar = (d1+d2+2*tr+tc-C)/2;
    ac = d1+tr+tc-ar;
    return;
}

void cal2(int R, int C, int tr, int tc, int d1, int d2, int &ar, int &ac){
    ar = (2*R+C-d1-d2-tc)/2;
    ac = d1-R+ar+tc;
    return;
}

void cal3(int R, int C, int d1, int d2, int &ar, int &ac){
    ac = (d1+d2-R+3)/2;
    ar = d1-ac+2;
    return;
}

void cal4(int R, int C, int d1, int d2, int &ar, int &ac){
    ac = (2*C+R-1-d1-d2)/2;
    ar = d1-C+ac+1;
    return;
}

int bs_r(int C, int l, int r, int cd){
    int res = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(drop_robot(mid, C) != -1){
            res = mid;
            if(cd == 0) l = mid+1;
            else r = mid-1;
        } else {
            if(cd == 0) r = mid-1;
            else l = mid+1;
        }
    }
    return res;
}

int bs_c(int R, int l, int r, int cd){
    int res = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(drop_robot(R, mid) != -1){
            res = mid;
            if(cd == 0) l = mid+1;
            else r = mid-1;
        } else {
            if(cd == 0) r = mid-1;
            else l = mid+1;
        }
    }
    return res;
}
int main(void){
    int R, C;
    int d[5] = {};
    get_size(R, C);

    d[1] = drop_robot(1, 1);
    d[2] = drop_robot(1, C);
    d[3] = drop_robot(R, 1);
    d[4] = drop_robot(R, C);
    
    int ar = 0, ac = 0;
    if(d[1] != -1 and d[2] != -1){ //hr top
        cal1(R, C, 1, 1, d[1], d[2], ar, ac);
    } else if(d[3] != -1 and d[4] != -1){ //hr bottom
        cal2(R, C, 1, 1, d[3], d[4], ar, ac);
    } else if(d[1] != -1 and d[3] != -1){ //vr left
        cal3(R, C, d[1], d[3], ar, ac);
    } else if(d[2] != -1 and d[4] != -1){ //vr right
        cal4(R, C, d[2], d[4], ar, ac);
    } else {
        if(d[1] != -1){
            int br = bs_r(1, 1, R, 0);
            int bc = bs_c(1, 1, C, 0);
            cal1(br, bc, 1, 1, d[1], drop_robot(1, bc), ar, ac);
        } else if(d[2] != -1){
            int br = bs_r(C, 1, R, 0);
            int bc = bs_c(1, 1, C, 1);
            cal1(br, C, 1, bc, drop_robot(1, bc), d[2], ar, ac);
        } else if(d[3] != -1){
            int br = bs_r(1, 1, R, 1);
            int bc = bs_c(R, 1, C, 0);
            cal2(R, bc, br, 1, d[3], drop_robot(R, bc), ar, ac);
        } else if(d[4] != -1){
            int br = bs_r(C, 1, R, 1);
            int bc = bs_c(R, 1, C, 1);
            cal2(R, C, br, bc, drop_robot(R, bc), d[4], ar, ac);
        } else {
            assert(0);
        }
    }
   
    answer(ar, ac);
    return 0;
}