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

int binarySearch(int *a,int key,int low,int high)
{
	int mid;
	if(low>high)
		return -1;
	mid=(low+high)/2;
	if(key==mid)
		return mid;
	if(key<a[mid])
		return(binarySearch(a,key,low,mid-1));
	return(binarySearch(a,key,mid+1,high));
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
	int retval=binarySearch(a,9,0,9);
	if(retval == -1)
	{
		printf("\n\nELEMENT IS NOT PRESENT IN THE ARRAY !");
	}
	else
	{
		printf("\n\nELEMENT IS PRESENT IN THE ARRAY !!!;");
		printf("\n\nAT LOCATION %d IN THE SORTED ( NOT IN ORIGINAL) ARRAY ",retval);
	}
	return 0;
}