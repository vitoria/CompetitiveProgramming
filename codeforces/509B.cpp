#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
#define INF 0x0f0f0f0f
using namespace std;

int main()
{
	int i,j,k,l,m,n,imax=0,imin=105;
	int a[105];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>imax)	imax=a[i];
		if(a[i]<imin)	imin=a[i];
	}
	if(imax - imin > m) {
		printf("NO\n");
	} else {
		printf("YES\n");

		for (i = 0; i < n; i++) {
			for (j = 0; j < a[i] - 1; j++) {
				printf("%d ",j%m+1);
			}
			printf("%d ", j % (m+1));
			printf("\n");
		}
	}
	
}