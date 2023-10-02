#include<stdio.h>

int main()
{
    char str[1000];
    scanf("%s", &str);
    char *arr[] = {"Geek", "Geeks", "Geekfor"};
    printf("String array Elements are:\n");
    for (int i = 0; i < 3; i++)
    {
         printf("%s\n", arr[i]);
    }
  return 0;
}
