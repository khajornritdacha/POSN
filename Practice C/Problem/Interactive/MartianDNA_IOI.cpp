//Task : https://oj.uz/problem/view/IOI16_dna
//Date : 2 Feb 2022
//1. find the longest consecutive zeros (O(logN))
//2. keep append new elements to the end while the number of consecutive zeros does not exceed the limit (takes extra O(mid) operation but we got consecutive zeros size of mid with only O(logN) operations so they offset each other)
//3. binary search to find the real endpoint (O(logN))
//4. find the prefix for our string

#include "dna.h"

#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

std::string analyse(int n, int t) {
    if(!make_test("0")) return string(n, '1');

    string str(n, '0');
    int l = 1, r = n, longest_zero = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(make_test(str.substr(0, mid))){
            longest_zero = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    assert(longest_zero != -1);

    str = str.substr(0, longest_zero);
    int cntz = longest_zero;
    while(str.size() < n){
        if(make_test(str+"1")){
            str += "1";
            cntz = 0;
        } else {
            cntz++;
            if(cntz > longest_zero){
                break;
            }
            str += "0";
        } 
    }

    l = 0, r = str.size()-longest_zero;
    int endpoint = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(make_test(str.substr(0, longest_zero+mid))){
            endpoint = longest_zero+mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    str = str.substr(0, endpoint);
    while(str.size() < n){
        if(make_test("1"+str)){
            str = "1" + str;
        } else {
            str = "0" + str;
        }
    }

    return str;
}                       