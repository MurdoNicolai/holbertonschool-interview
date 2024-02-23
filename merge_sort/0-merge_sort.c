#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size) {
    size_t i, j, k, mid;
    int *temp; // Single temporary array for both left and right sub-arrays

    if (size <= 1) {
        return;
    }

    mid = size / 2;

    // Allocate enough space for both sub-arrays
    temp = (int*)malloc(size * sizeof(int));

    // Copy elements to the temporary array as left and right sub-arrays
    for (i = 0; i < mid; i++) {
        temp[i] = array[i];
    }
    for (i = mid; i < size; i++) {
        temp[i] = array[i]; // Corrected index for right sub-array (no adjustment needed)
    }

    merge_sort(temp, mid); // Sort left sub-array
    merge_sort(temp + mid, size - mid); // Sort right sub-array (offset by mid)

    printf("Merging...\n");
    printf("[left]: ");
    for (i = 0; i < mid; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
    printf("[right]: ");
    for (i = mid; i < size; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    // Merge sorted sub-arrays back to the original array
    i = 0, j = mid, k = 0;
    while (i < mid && j < size) {
        if (temp[i] <= temp[j]) {
            array[k++] = temp[i++];
        } else {
            array[k++] = temp[j++];
        }
    }

    // Copy remaining elements from the temporary array
    while (i < mid) {
        array[k++] = temp[i++];
    }
    while (j < size) {
        array[k++] = temp[j++];
    }

    printf("[Done]: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(temp);
}
