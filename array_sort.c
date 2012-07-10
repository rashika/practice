#include<stdio.h>

void sort(int *a , int n)
{
	int i , j , min , temp;
	for(i = 0 ; i < n ; i++)
	{
		min = i;
		for(j = i+1 ; j < n ; j++)
		{
			if(*(a + min) > *(a +j))
			{
				temp = j;
				j = min; 
				min = temp;
			}
		}
		temp = *(a+i);
		*(a+i) = *(a+min);
		*(a+min)=temp;
	}
}

int main()
{
	int a[] = {3,4,1,2,5};
	sort(a,5);
	int i;
	for(i = 0;i<5 ; i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
