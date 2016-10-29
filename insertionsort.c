/***********************************
* Insertion sort
************************************/

#include <stdio.h>

int main()
{
    int *arr;
	int size;
	printf("Enter size of the array\n");
	scanf("%d",&size);
	arr=(int *)malloc(sizeof(int)*size);
	printf("Enter elements of the array\n");
	int i,j,temp;
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}

	//displays before sorting
    for(i=0;i<size;i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");

    //insertion sort logic here
    for(i=1;i<size;i++)
    {
        temp=arr[i];

        for(j=i-1;j>=0 && temp < arr[j];j--)
            arr[j+1]=arr[j];
        arr[j+1]=temp;
    }

 	//displays after sorting
    for(i=0;i<size;i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");
}
