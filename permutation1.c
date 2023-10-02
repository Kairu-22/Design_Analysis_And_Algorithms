//Input: Permutation of {1,2,3..,} with one element appearing twice, making it is a sequence of n+1 integers.
//output: Identify the elements twice in O(n) and O(1) space complexity.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    printf("Write the value of n: ");
    scanf("%d", &n);
    int arr[n+1];
    for(i=0;i<n;i++)
    {
        printf("Enter Element: ");
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for(i=0;i<n+1;i++)
    {
        sum += arr[i];
    }

    printf("Duplicate value is %d", sum - n*(n+1)/2);


}