#include<bits/stdc++.h>
using namespace std;
int data[999999];
int main()
{
	int n;
	scanf(" %d",&n);
	scanf(" %d",&data[0]);
	int cou=1,num,k;
	for(int i=1;i<n;i++)
	{
		scanf(" %d",&num);
		k=upper_bound(data,data+cou,num-1)-data;
		if(k==cou) cou++;
		data[k]=num;
	}
	printf("%d",cou);
}

