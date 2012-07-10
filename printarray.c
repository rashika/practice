#include<stdio.h>

void array_print(int *a, int n)
{
	int i;
	for(i = 0 ;i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

/*int main()
{
	int a[] = {1,2,3,4};
	array_print(a,4);
	return 0;
}*/
