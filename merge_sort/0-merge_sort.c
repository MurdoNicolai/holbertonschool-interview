#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *array, size_t size) {
    size_t i, j, k, mid;

    if (size <= 1) {
        return;
    }

    mid = size / 2;
    int *left = (int*)malloc(mid * sizeof(int));
    int *right = (int*)malloc((size - mid) * sizeof(int));

    for (i = 0; i < mid; i++) {
        left[i] = array[i];
    }
    for (i = mid; i < size; i++) {
        right[i - mid] = array[i];
    }

    merge_sort(left, mid);
    merge_sort(right, size - mid);

    printf("Merging...\n");
    printf("[left]: ");
    for (i = 0; i < mid; i++) {
        printf("%d ", left[i]);
    }
    printf("\n");
    printf("[right]: ");
    for (i = 0; i < size - mid; i++) {
        printf("%d ", right[i]);
    }
    printf("\n");

    i = 0, j = 0, k = 0;
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
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(left);
    free(right);
}
