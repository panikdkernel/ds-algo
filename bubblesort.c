/*********************************
* Bubble sort
**********************************/

#include <stdio.h>
#include <malloc.h>

int main(int argc, char const *argv[])
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
    for(i=0;i<size;i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    for(i=0;i<size;i++)
    {
        printf(" %d ",arr[i]);
    }


	return 0;
}
