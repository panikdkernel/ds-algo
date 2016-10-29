#include <stdio.h>
#include <stdlib.h>

void merge(int *a,int *L,int lsize,int* R,int rsize)
{
	int i,j,k;
	i=0;j=0;k=0;

	while(i<lsize && j<rsize)
	{
		if(L[i]<R[j])
			a[k++]=L[i++];
		else
			a[k++]=R[j++];
	}
	while(i<lsize) a[k++]=L[i++];
	while(j<rsize) a[k++]=R[j++];
}
void mergeSort(int *a,int n)
{
	int mid,i,*L,*R;
	if(n<2) return;

	mid=n/2;
	L=(int*)malloc(mid*sizeof(int));
	R=(int*)malloc((n-mid)*sizeof(int));

	for(i=0;i<mid;i++)
		L[i]=a[i];
	for(i=mid;i<n;i++)
		R[i-mid]=a[i];

	mergeSort(L,mid);
	mergeSort(R,n-mid);
	merge(a,L,mid,R,n-mid);
	free(L);
	free(R);
}
int main(int argc, char const *argv[])
{
	int arr[10]={3,532,343,635,34,65,324,54,23,65};
	mergeSort(arr,10);
	for (int i = 0; i < 10; ++i)
	{
		printf(" %d ",arr[i]);
	}
	printf("\n");
	return 0;
}