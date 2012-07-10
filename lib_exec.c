#include<library.h>
#include<stdio.h>

int main()
{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	swap(&a,&b);
	printf("%d %d\n",a,b);
	int arr[] = {1,4,2,0};
	sort(arr,4);
	array_print(arr,4);
	return 0;
}
