#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,ans;
int main(){
	scanf("%d%d%d%d",&n,&a,&b,&c);
	if(a > b) swap(a,b);
	if(c == 0){
		if(a == b) printf("2");
		else printf("0");
	}
	else{
		if(a == b) printf("%d",4*a+2);
		else if(b - a == 1) printf("%d",b*2);
		else printf("0");
		
	}
}
