#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
int main()

{
	int done = FALSE;
	int n;

scanf("%d",&n);
	int j = 0;
	while(done<n)
	{

		int* a = (int*)malloc(n* sizeof(int));
		int i;
		for (i=0; i<n; i++)
		a[i] = i;
		j++;
		printf("%d\n",j);
		done++;
	}
	return 0;
}

