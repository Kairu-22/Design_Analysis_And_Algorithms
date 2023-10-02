#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student record
struct Student {
    int roll_number;
    char name[50];
};

void merge(struct Student arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    struct Student left_half[n1];
    struct Student right_half[n2];

    for (i = 0; i < n1; i++)
        left_half[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        right_half[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (left_half[i].roll_number <= right_half[j].roll_number) {
            arr[k] = left_half[i];
            i++;
        } else {
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_half[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(struct Student arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *student_records = malloc(n * sizeof(struct Student));

    if (student_records == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read student records from the user
    for (int i = 0; i < n; i++) {
        printf("Enter Roll No. for Student %d: ", i + 1);
        scanf("%d", &student_records[i].roll_number);
        getchar(); 

        printf("Enter Name for Student %d: ", i + 1);
        fgets(student_records[i].name, sizeof(student_records[i].name), stdin);
        student_records[i].name[strcspn(student_records[i].name, "\n")] = '\0';
    }

    // Perform merge sort on student_records based on roll numbers
    mergeSort(student_records, 0, n - 1);

    // Open a file for writing the sorted records
    FILE *output_file = fopen("sorted_records.txt", "w");
    if (output_file == NULL) {
        printf("Error opening the output file.\n");
        free(student_records);
        return 1;
    }

    // Print sorted records to the console for debugging
    for (int i = 0; i < n; i++) {
    printf("%d %s\n", student_records[i].roll_number, student_records[i].name);
}


    // Write sorted records to the output file
    for (int i = 0; i < n; i++) {
        fprintf(output_file, "%d %s\n", student_records[i].roll_number, student_records[i].name);
    }

    // Close the output file
    fclose(output_file);

    // Free allocated memory
    free(student_records);

    return 0;
}
