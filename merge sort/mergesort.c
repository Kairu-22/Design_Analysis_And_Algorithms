#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student record
struct Student {
    int roll_number;
    char name[100];
};

// Merge two subarrays of student records
void merge(struct Student arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    struct Student left_half[n1];
    struct Student right_half[n2];

    // Copy data to temporary arrays left_half[] and right_half[]
    for (i = 0; i < n1; i++)
        left_half[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        right_half[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
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

    // Copy the remaining elements of left_half[], if any
    while (i < n1) {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right_half[], if any
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

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
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
        getchar(); // Consume the newline character left in the input buffer

        printf("Enter Name for Student %d: ", i + 1);
        fgets(student_records[i].name, sizeof(student_records[i].name), stdin);
        student_records[i].name[strcspn(student_records[i].name, "\n")] = '\0'; // Remove trailing newline
    }

    // Perform merge sort on student_records based on roll numbers
    mergeSort(student_records, 0, n - 1);

    // Print sorted records
    printf("\nSorted Student Records:\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", student_records[i].roll_number, student_records[i].name);
    }

    // Free allocated memory
    free(student_records);

    return 0;
}
