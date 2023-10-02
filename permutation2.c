//Input: Permutation of {1,2,3..,} with two element appearing twice, making it is a sequence of n+2 integers.
//output: Identify the elements twice in O(n) and O(1) space complexity.
#include <stdio.h>
#include <math.h> // Include the math.h library

int main() {
    int n, i;
    printf("Write the value of n: ");
    scanf("%d", &n);
    int arr[n + 2];
    for (i = 0; i < n + 2; i++) {
        printf("Enter Element: ");
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for (i = 0; i < n + 2; i++) {
        sum += arr[i];
    }
    int x, y;
    int z = sum - n * (n + 1) / 2;
    sum = 0; // Reset sum
    for (i = 0; i < n + 2; i++) {
        sum += arr[i] * arr[i];
    }
    int p = sum - n * (n + 1) * (2 * n + 1) / 6;
    int a = 2, b = -2 * z, c = z * z - p;
    int d = sqrt((b * b) - 4 * a * c);
    y = (-b + d) / (2 * a); // Corrected the division operator
    x = z - y; // Calculate x using z and y
    printf("Sum of duplicate value is %d\n", sum - n * (n + 1) / 2);
    printf("x = %d\n", x); // Print the value of x
    printf("y = %d\n", y); // Print the value of y

    return 0;
}