#include <stdio.h>
void shellSort(int *a,int n)
{
	int gap,i,j,temp;
	gap=n/2;
	while(gap>0)
	{
		for(i=gap;i<n;i++)
		{
			temp=a[i];
			for(j=i-gap;j>=0 && temp<a[j];j-=gap)
				a[j+gap]=a[j];
			a[j+gap]=temp;
		}
		gap=gap/2;

	}

}
int main(int argc, char const *argv[])
{
	int arr[10]={3,532,343,635,34,65,324,54,23,65};
	shellSort(arr,10);
	for (int i = 0; i < 10; ++i)
	{
		printf(" %d ",arr[i]);
	}
	printf("\n");
	return 0;
}