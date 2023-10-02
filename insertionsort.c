#include<stdio.h>
#include<math.h>

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i=1;i<n;i++)
	{
		key = arr[i];
		j=i-1;
		
		while (j>=0 && arr[j]> key)
		{
			arr[j+1]=arr[j];
			j= j-1;
		}
		arr[j+1] =key;
	}
}

int main()
{
int n;
printf("Enter the number of elements in the array: ");
scanf("%d", &n);

int arr[n], i;
printf("Enter the elements of the array:\n");
for (i = 0; i < n; i++)
{ scanf("%d", &arr[i]);}

insertionSort(arr,n);
printArray(arr, n);

return 0;
}
