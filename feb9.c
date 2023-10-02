// Find output value of (1+i)^n where i=square root -1 in O(log2(n)) time and O(log2(n)) space

#include<stdio.h>
#include<complex.h>

double complex power(double complex base, int exponent){
    if (exponent == 0) {
        return 1;
    } else if (exponent % 2 == 0) {
        double complex temp = power(base, exponent / 2);
        return temp * temp;
    } else {
        return base * power(base, exponent - 1);
    }
}


int main(){
    double complex i=I;
    int n;

    printf("Enter the value of n:");
    scanf("%d",&n);

    double complex result = power(1+i, n);

    printf("Result: %.2f + %.2fi\n", creal(result), cimag(result));
}