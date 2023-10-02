#include <stdio.h>
#include <limits.h>
#include <stdlib.h> 
#include <string.h>


int max3(int a, int b, int c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}


int maxCrossingSum(int arr[], int l, int m, int h) {
    
    int i, sum = 0;
    int left_sum = INT_MIN;
    for ( i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    
    sum = 0;
    int right_sum = INT_MIN;
    for ( i = m; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    
    return max3(left_sum + right_sum - arr[m], left_sum, right_sum);
}


int maxSubArraySum(int arr[], int l, int h) {
    
    if (l > h)
        return INT_MIN;
    if (l == h)
        return arr[l];

    int m = (l + h) / 2;
    
    return max3(maxSubArraySum(arr, l, m - 1),
                maxSubArraySum(arr, m + 1, h),
                maxCrossingSum(arr, l, m, h));
}


int main() {
    int n,i; 
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    char **arr = (char **)malloc(n * sizeof(char *));
    int *intArr = (int *)malloc(n * sizeof(int));  

    printf("Enter %d numbers with space:\n", n);
    for (i = 0; i < n; i++) {
        arr[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", arr[i]);
        intArr[i] = atoi(arr[i]);
    }
    
    printf("Integer array elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", intArr[i]);
    }

    int max_sum = maxSubArraySum(intArr, 0, n - 1);
    printf("Maximum sum of sub array is %d\n", max_sum);
    return 0;
}

