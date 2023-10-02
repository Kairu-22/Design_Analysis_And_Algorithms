#include<stdio.h>

int main()
{
    printf("Matrix Multiplication\n");
    int n, i, j;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    int arr1[n][n], arr2[n][n];
    
    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr1[i][j]); 
        }
    }
    
    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr2[i][j]); 
        }
    }
    
    printf("The first matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
    
    printf("The second matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
    
    //matrix multiplication
    
    int k;
    int mult[n][n];
    printf("The matrix obtained is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
        mult[i][j]=0;    
           for(k = 0; k < n; k++)    
           {
		   mult[i][j]+=arr1[i][k]*arr2[k][j];  
            }
        }
            
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", mult[i][j]);
        }
        printf("\n");
    }
    return 0;
}

