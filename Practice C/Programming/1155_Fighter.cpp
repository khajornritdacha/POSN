#include <stdio.h>
int a[1000000];
main()
{
int P,Pe,Po,i,e=0,o=0;
scanf("%d",&P);
Pe=P;
Po=P;
for(i=0;i<2*P;i++)
{
	scanf("%d",&a[i]);
}
for(i=0;i<2*P;i++)
{
	e=0;
	o=0;
	if(a[i]%2==0)
	{
	if(i<2)
	{
	e=e+1;
	}
	else if(i>=2)
	{
	if(a[i-1]%2!=0)
	{
	e=e+1;
	}
	else if(a[i-1]%2==0)
	{
		if(a[i-2]%2==0)
		{
		e=e+3;
		}
		else if(a[i-2]%2!=0)
		{
		e=e+1;
		}
	}
	}
    }

    if(a[i]%2!=0)
	{
	if(i<2)
	{
	o=o+1;
	}
	else if(i>=2)
	{
	if(a[i-1]%2==0)
	{
	o=o+1;
	}
	else if(a[i-1]%2!=0)
	{
		if(a[i-2]%2!=0)
		{
		o=o+3;
		}
		else if(a[i-2]%2==0)
		{
		o=o+1;
		}
	}
    }
    }
	Pe=Pe-o;
	if(Pe<=0)
	{
		printf("1\n");
		printf("%d",a[i]);
		break;
	}
	Po=Po-e;
	if(Po<=0)
	{
		printf("0\n");
		printf("%d",a[i]);
		break;
	}
}
}
