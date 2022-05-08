#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,ans,arr[20];

void gen(int x,int y,int z,int lv){
	if(lv == n+1){
		int chk = 1;
		for(int i=1;i<n;i++) if(arr[i] == arr[i+1]) chk = 0;
		if(arr[n] == arr[1]) chk = 0;
		if(chk) ans++;
		return;
	}
	if(x < a){
		arr[lv] = 1;
		gen(x+1,y,z,lv+1);
	}
	if(y < b){
		arr[lv] = 2;
		gen(x,y+1,z,lv+1);
	}
	if(z < c){
		arr[lv] = 3;
		gen(x,y,z+1,lv+1);
	}
}

int main(){
	scanf("%d%d%d%d",&n,&a,&b,&c);
	gen(0,0,0,1);
	printf("%d",ans);
}
