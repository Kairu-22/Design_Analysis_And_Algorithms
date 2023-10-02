//number of times substring occurs in the main string take the dynamic input from the user.
#include<stdio.h>
#include<string.h>

int countSubstringOccurrences(const char *mainString, const char *substring) {
    int count = 0;
    int mainLen = strlen(mainString);
    int subLen = strlen(substring);

    for (int i = 0; i <= mainLen - subLen; i++) 
	{
        if (strncmp(mainString + i, substring, subLen) == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    char mainString[1000];
    char substring[100];

    printf("Enter the main string: ");
    scanf("%s", mainString);

    printf("Enter the substring: ");
    scanf("%s", substring);

    int occurrences = countSubstringOccurrences(mainString, substring);
    printf("The substring '%s' occurs %d times in the main string.\n", substring, occurrences);

    return 0;
}

