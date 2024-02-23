#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size) {
    // Base case: Array with 1 or 0 elements is already sorted
    if (size <= 1) {
        return;
    }

    // Determine the split point based on the requirement to have the left sub-array <= the right sub-array
    size_t mid = size / 2;

    // Allocate memory for temporary arrays (only one call to malloc)
    int *left = (int*)malloc(mid * sizeof(int));
    int *right = (int*)malloc((size - mid) * sizeof(int));

    // Copy elements to the temporary arrays
    for (size_t i = 0; i < mid; i++) {
        left[i] = array[i];
    }
    for (size_t i = mid; i < size; i++) {
        right[i - mid] = array[i];
    }

    // Recursively sort the left and right sub-arrays
    merge_sort(left, mid);
    merge_sort(right, size - mid);

    // Merge the sorted sub-arrays back into the original array
    int i = 0, j = 0, k = 0;
    while (i < mid && j < size - mid) {
        if (left[i] <= right[j]) {
            array[k++] = left[i++];
        } else {
            array[k++] = right[j++];
        }
    }

    // Copy remaining elements from the left sub-array (if any)
    while (i < mid) {
        array[k++] = left[i++];
    }

    // Copy remaining elements from the right sub-array (if any)
    while (j < size - mid) {
        array[k++] = right[j++];
    }

    // Free the temporary memory
    free(left);
    free(right);
}

int main() {
    int array[] = {5, 2, 8, 1, 3};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Unsorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    merge_sort(array, size);

    printf("Sorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
