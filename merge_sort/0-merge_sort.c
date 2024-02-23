#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size) {
    if (size <= 1) {
        return;
    }

    size_t mid = size / 2;
    int *left = (int*)malloc(mid * sizeof(int));
    int *right = (int*)malloc((size - mid) * sizeof(int));

    for (size_t i = 0; i < mid; i++) {
        left[i] = array[i];
    }
    for (size_t i = mid; i < size; i++) {
        right[i - mid] = array[i];
    }

    merge_sort(left, mid);
    merge_sort(right, size - mid);

    printf("Merging...\n");
    printf("[left]: ");
    for (size_t i = 0; i < mid; i++) {
        printf("%d ", left[i]);
    }
    printf("\n");
    printf("[right]: ");
    for (size_t i = 0; i < size - mid; i++) {
        printf("%d ", right[i]);
    }
    printf("\n");

    size_t i = 0, j = 0, k = 0;
    while (i < mid && j < size - mid) {
        if (left[i] <= right[j]) {
            array[k++] = left[i++];
        } else {
            array[k++] = right[j++];
        }
    }

    while (i < mid) {
        array[k++] = left[i++];
    }

    while (j < size - mid) {
        array[k++] = right[j++];
    }

    printf("[Done]: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(left);
    free(right);
}
