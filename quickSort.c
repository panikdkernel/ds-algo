#include <stdio.h>
int partition(int *a, int start, int end)
{
	int pivot=a[end];
	int pindex=start;
	int temp;
	for (int i = start; i < end; i++)
	{
		if(a[i]<=pivot)
		{
			temp=a[i];
			a[i]=a[pindex];
			a[pindex]=temp;
			pindex++;
		}
	}
	temp=a[end];
	a[end]=a[pindex];
	a[pindex]=temp;	
	return pindex;

}

void quickSort(int *a, int start, int end)
{
	if (start < end)
	{
		int pindex=partition(a,start,end);
		quickSort(a,start,pindex-1);
		quickSort(a,pindex+1,end);
	}
}
int main(int argc, char const *argv[])
{
	int a[10]={7,3,8,5,6,2,9,11,1,4};
	quickSort(a,0,9);
	for(int i=0;i<10;i++)
	{
		printf(" %d ",a[i]);
	}
	printf("\n");
	return 0;
}